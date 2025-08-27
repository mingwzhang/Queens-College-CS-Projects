
// Mingwei Zhang

//Professor thread

import java.util.Random;

public class Professor extends Thread
{
    private ClassroomMonitor class1;
    private ClassroomMonitor class2;
    private OfficeHoursMonitor officeHour;

    private Object block = new Object(); // timer uses this to signal class/office hour start

    private Random rand = new Random();

    // constructor sets name and links monitors
    public Professor(int id ,ClassroomMonitor c1, ClassroomMonitor c2, OfficeHoursMonitor offHr) {
        setName("Professor-" + id);  // unique thread name
        this.class1 = c1;
        this.class2 = c2;
        this.officeHour = offHr;
    }

    public void run() {
        try {
            Block();  // wait for timer to start class 1
            Thread.sleep(rand.nextInt(200));
            msg("Professor Arrived. Class 1 starts.");
            class1.startClass();
            
            Block();  // wait for timer to start class 2
            Thread.sleep(rand.nextInt(200));
            msg("Arrived. Class 2 starts.");
            class2.startClass(); 

            Block(); // wait for timer to start office hour
            Thread.sleep(rand.nextInt(100));
            msg("Wait for students to get in line for office hour.");
            
            officeHour.waitForAllDecisions(); // block until all students decided
            msg("Finished waiting. Total students in office hour line: " + officeHour.studentNumInLine());

            while (officeHour.studentNumInLine() > 0) { // answer questions one by one
                String studentName = officeHour.nexStudent();
                msg("Answering question for " + studentName);
                Thread.sleep(rand.nextInt(500) + 100);
            }

            msg("All questions answered, office hours over.");
            officeHour.endSession(); // end signal for students

        } catch (Exception e) {

        }
    }

    // Methods used by timer to unblock professor
    public void startClass() {
        synchronized (block) {block.notify();}
    }

    public void waitOfficeHours() {
        synchronized (block) {block.notify();}
    }
    public void startOfficeHours() {
        synchronized (block) {block.notify();}
    }

    // Methods used by timer to block professor
    public void Block() throws InterruptedException
    {
        synchronized (block) {
            block.wait();  // wait for signal from timer
        }
    }

    public static long time = System.currentTimeMillis();

    public void msg(String m) {
        System.out.println("["+(System.currentTimeMillis()-time)+"] "+getName()+": "+m);
    }
}