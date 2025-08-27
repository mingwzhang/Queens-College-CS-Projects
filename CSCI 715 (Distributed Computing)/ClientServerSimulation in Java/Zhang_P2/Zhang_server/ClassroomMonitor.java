
public class ClassroomMonitor   
{
    private int capacity;
    private int seatsTaken = 0;
    private boolean classStarted = false;
    private boolean classEnded = false;
    private String absentReason = "";
    private int classCount;

    public ClassroomMonitor(int cap, int cc)
    {
        this.capacity = cap;
        this.classCount = cc;
    }

    public String getAbsentReason()
    {
        return absentReason;
    }

    // synchronized: only one student can attempt to enter at a time (to prevent race condition)
    public synchronized boolean studentEnterClass(String studentName) {
        if (classStarted) {
            absentReason = "Student is late.";
            return false;
        }
        if (seatsTaken < capacity) {
            seatsTaken++;
            msg("Grabbed a seat for class " + classCount + " (" + seatsTaken + "/" + capacity + ").");
            return true;
        }else{
            absentReason = "Class " + classCount + " is full";
        }
        return false;
    }

    // professor starts the class and wakes all students waiting
    public synchronized void startClass() {
        classStarted = true;
        notifyAll();
    }

    // students block until professor signals class start
    public synchronized void waitForStart() throws InterruptedException {
        while (!classStarted) wait();
    }

    //Used in Timer.java to signal students to wait
    public synchronized void endClass() {
        classEnded = true;
        notifyAll();

        if (endSecondClassConfirmed()) msg("All classes done, confirmed.");
    }
    
    // checks if this was the second class and confirms end
    public boolean endSecondClassConfirmed()
    {
        return classCount == 2 & classEnded;
    }

    // students wait for professor to end the class
    public synchronized void waitForEnd() throws InterruptedException {
        while (!classEnded) wait();
    }

    
    public static long time = System.currentTimeMillis();

    public void msg(String m) {
        String caller = Thread.currentThread().getName();
        System.out.printf("[%d] %s: %s%n", System.currentTimeMillis() - time, caller, m);
    }
}