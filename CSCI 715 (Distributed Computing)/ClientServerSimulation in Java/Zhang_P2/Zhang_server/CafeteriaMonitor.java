
public class CafeteriaMonitor 
{
    int numTables, numSeats;
    private String[][] tableAndSeats; // Blocks table if full

    int totalSeatsCount;
    public int studentCount;
    
    public CafeteriaMonitor(int t, int s) {     //Constructor
        this.numTables = t;
        this.numSeats = s;
        this.totalSeatsCount = numSeats * numTables;
        this.tableAndSeats = new String[numTables][numSeats];
        for(int x = 0; x < numTables; x++)      //  initialize seating layout for all cafeteria tables, starting as null for each seat
        {
            for(int y = 0; y < numSeats; y++)
            {
                this.tableAndSeats[x][y] = null;
            }
        }
    }

    public synchronized int TakeSeats(String student) { // synchronized: only one student can pick a seat at a time
        for (int t = 0; t < numTables; t++) {
            for (int s = 0; s < numSeats; s++) {
                if (tableAndSeats[t][s] == null) {
                    tableAndSeats[t][s] = student;
                    totalSeatsCount--;
                    studentCount++;
                    msg("Goes to Cafeteria table " + (t+1) + ", seat " + (s+1) + " (Seats left: " + totalSeatsCount + ").");
                    return t;
                }
            }
        }
        return -1; // no seat available, student will leave. Checked in Student thread if tableId < 0 
    }

    // wait at the specific table until notified to go to class 2
    //"platoon policy" where students wait together (on shared table object) until signaled
    public void waitAtTable(int tableId) throws InterruptedException {  
        synchronized (tableAndSeats[tableId]) {
            tableAndSeats[tableId].wait();
        }
    }

    public void signalTable(int tableId) {  // notifies all students at the table to leave at once
        synchronized (tableAndSeats[tableId]) {
            tableAndSeats[tableId].notifyAll();
        }
    }

    //getters
    public int getNumTables() {
        return numTables;
    }
    //getters
    public int getNumStudent() {
        return studentCount;
    }

    public static long time = System.currentTimeMillis();
    public void msg(String m) {
        String caller = Thread.currentThread().getName();
        System.out.printf("[%d] %s: %s%n", System.currentTimeMillis() - time, caller, m);
    }
}