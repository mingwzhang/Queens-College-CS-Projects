
// Mingwei Zhang

// Timer thread

import java.util.Random;

public class Timer extends Thread
{
    private ClassroomMonitor class1, class2;
    private CafeteriaMonitor cafeteria;
    private OfficeHoursMonitor officeHr;

    private Professor prof;

    // simulation timings (in ms)
    private long first_class_delay = 1000;  // “10 AM”
    private long first_class_duration = 2000; // duration for student in class 1 before moving to cafeteria
    private long break_duration = 1500;  // total break
    private long second_class_delay = 500;   // notify before second class
    private long second_class_duration = 2000;  // duration for student in class 2 before moving to office hour
    private Random rand = new Random();
    
    // constructor links all monitors and professor
    public Timer(Professor prof, ClassroomMonitor c1, ClassroomMonitor c2, CafeteriaMonitor caf, OfficeHoursMonitor off) { 
        setName("Timer"); 
        this.prof = prof;
        this.class1 = c1;
        this.class2 = c2;
        this.cafeteria = caf;
        this.officeHr = off;
    }

    public void run() { //triggers timeline of students events from class 1 to cafeteria to class 2 to office hour
        try {
            Thread.sleep(first_class_delay); // delay before class 1 starts
            msg("First class is starting.");
            prof.startClass(); //leads to class1.startClass()

            Thread.sleep(first_class_duration);  //  class 1 duration
            msg("First class ends.");
            class1.endClass();  

            Thread.sleep(break_duration);    // cafeteria duration

            msg("Break is up. Notifying cafeteria tables to head to second class. Remaining students: " + cafeteria.studentCount);
            LeaveCafeteriaEvent();

            msg("10 minutes befoe second class is starting");
            Thread.sleep(second_class_delay);
            prof.startClass(); //leads to class2.startClass()

            Thread.sleep(second_class_duration);  // class 2 duration
            msg("Second class ends.");
            class2.endClass();
            Thread.sleep(1000);
            
            msg("Office hours available.");
            prof.waitOfficeHours(); //same as prof.startClass(); that remove block, but with different method name
            Thread.sleep(100);
            officeHr.prepareOfficeHour(); //students decide if they should line up for office hour.

        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    // notify each table in cafeteria to leave in order
    public void LeaveCafeteriaEvent() throws InterruptedException
    {
        for (int i = 0; i < cafeteria.getNumTables(); i++) {
            cafeteria.signalTable(i);  // notify students at each table
            Thread.sleep(rand.nextInt(100));
        }
    }

    public static long time = System.currentTimeMillis();
    public void msg(String m) {
        System.out.println("["+(System.currentTimeMillis()-time)+"] "+getName()+": "+m);
    }
}