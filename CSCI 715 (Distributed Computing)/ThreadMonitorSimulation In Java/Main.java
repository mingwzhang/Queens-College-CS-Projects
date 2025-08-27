
// Mingwei Zhang
// Main class

public class Main{
    public static void main(String[] args)
    {
        int numPeople = 15; // classroom seat capacity
        int numStudents = 20;  // total student threads
        int numTables = 4;   // cafeteria tables
        int numSeats =3; // seats per table

        // create monitors for synchronization across shared resources
        ClassroomMonitor classroom1Monitor = new ClassroomMonitor(numPeople, 1);
        ClassroomMonitor classroom2Monitor = new ClassroomMonitor(numPeople, 2);

        CafeteriaMonitor cafeteriaMonitor = new CafeteriaMonitor(numTables, numSeats);
        OfficeHoursMonitor officeHoursMonitor = new OfficeHoursMonitor();

        // start professor thread (handles class start/end and office hour Q&A)
        Professor prof = new Professor(1,classroom1Monitor, classroom2Monitor, officeHoursMonitor);
        prof.start();

        // start timer thread (controls when events such as class start or end happen)
        Timer timer = new Timer(prof, classroom1Monitor, classroom2Monitor, cafeteriaMonitor, officeHoursMonitor);
        timer.start();
        
        // create and start all student threads
        for (int i = 1; i <= numStudents; i++) {
            Student s = new Student(i, classroom1Monitor, classroom2Monitor, cafeteriaMonitor, officeHoursMonitor);
            s.start();
        }
    }
}