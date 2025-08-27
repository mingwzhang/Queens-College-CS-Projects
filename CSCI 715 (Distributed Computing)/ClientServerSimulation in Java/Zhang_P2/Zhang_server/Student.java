
import java.util.*;

public class Student extends Thread
{
    // all monitors used by student
    private ClassroomMonitor class1, class2;
    private CafeteriaMonitor cafeteria;
    private OfficeHoursMonitor officeHr;

    private Random rand = new Random();

    // constructor sets name and links monitors
    public Student(int id, ClassroomMonitor c1, ClassroomMonitor c2, CafeteriaMonitor caf, OfficeHoursMonitor offhr) {
        setName("Student-" + id); //unique thread name
        this.class1 = c1;
        this.class2 = c2;
        this.cafeteria = caf;
        this.officeHr = offhr;
    }

    public void run() {
        try {
            toClass1Monitor();
            toCafeteriaAfterClass();  //Exits out if cafeteria is full
            toClass2Monitor(); 
            toOfficeHourMonitor(); 
        } catch (Throwable e) {}
    }
    

    public void toClass1Monitor() throws InterruptedException
    {
            boolean enterClass1 = class1.studentEnterClass(getName());
            String absentReason1 = class1.getAbsentReason();

            Thread.sleep(rand.nextInt(200)); // random arrival time

            if(!enterClass1) // try to enter first class, leads 
            {
                msg("Class 1 missed. Reason: " + absentReason1); // get reason if rejected
            }else{          // attend first class if got seat
                class1.waitForStart();    // block until professor starts class
                msg("Now attending class 1.");
                class1.waitForEnd();   // block until class ends
            }
    }

    public class NoSeatException extends RuntimeException { }
    public void  toCafeteriaAfterClass() throws InterruptedException, NoSeatException
    {
        int tableId = cafeteria.TakeSeats(getName());  // student tries to get into cafeteria after class 1
        if (tableId < 0) {      //// tableId from cafeteria monitor returns -1 if no seats available
            msg("Cafeteria full. Leaving school.");
            throw new NoSeatException();
        }  

        // wait until timer notifies the table to go to class 2
        cafeteria.waitAtTable(tableId);  
        msg("Leaving cafeteria table " + (tableId + 1) + ". Trying to enter class 2.");
    }

    public synchronized void toClass2Monitor() throws InterruptedException
    {
            boolean enterClass2 = class2.studentEnterClass(getName());  // try to enter class 2
            String absentReason2 = class2.getAbsentReason();  // get reason if rejected

            Thread.sleep(rand.nextInt(200));

            if(!enterClass2)   // class full or already started 
            {
                msg("Class 2 missed. Reason: " + absentReason2);
            }else{
                class2.waitForStart();   // block until professor starts class
                msg("Now attending class 2.");
                class2.waitForEnd();    // block until class ends
                
                if(class2.endSecondClassConfirmed())  // confirms class 2 ended 
                {
                    msg("Leave class 2.");
                    officeHr.addStudentCount(); // let office hour know this student will make a decision
                }
            }
    }

    // student decides whether to join or skip office hour
    public class NotJoinOfficeHourExpception extends RuntimeException{}
    public void toOfficeHourMonitor() throws Throwable, NotJoinOfficeHourExpception {
        int randomNum = new Random().nextInt(10) + 1; // random 1–10 to decide
        Boolean joinOfficeHr = officeHr.joinOfficeHour(getName(), randomNum);  // try to join based on random number
        Thread.sleep(rand.nextInt(200)); // randomize delay before deciding
        if(joinOfficeHr)
        {
            msg("Decides to join office hour. Waiting in line.");
            officeHr.registeredStudentDecision();   // notify monitor decision is made
        }else{
            msg("Decides to leave offce hour.");
            officeHr.registeredStudentDecision(); // still notify even if skipped
            throw new NotJoinOfficeHourExpception();
        }
    }

    public static long time = System.currentTimeMillis();

    public void msg(String m) {
        System.out.println("["+(System.currentTimeMillis()-time)+"] "+getName()+": "+m);
    }
}