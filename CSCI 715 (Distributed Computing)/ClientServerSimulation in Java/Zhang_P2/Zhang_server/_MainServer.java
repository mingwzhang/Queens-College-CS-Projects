
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class _MainServer {
    private static final int PORT = 3000;

    public static void main(String[] args) {
        int numPeople = 15; // classroom seat capacity
        int numTables = 4; // number of cafeteria tables
        int numSeats = 3; // seats per table

        // shared monitors
        ClassroomMonitor class1 = new ClassroomMonitor(numPeople, 1);
        ClassroomMonitor class2 = new ClassroomMonitor(numPeople, 2);
        CafeteriaMonitor cafeteria = new CafeteriaMonitor(numTables, numSeats);
        OfficeHoursMonitor officeHr = new OfficeHoursMonitor();
        
        //  shared professor and timer instances
        Professor professor = new Professor(1, class1, class2, officeHr);
        Timer timer = new Timer(professor, class1, class2, cafeteria, officeHr);

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Main server started on port " + PORT);
            System.out.println("Simulation parameters:");
            System.out.println("  Classroom capacity: " + numPeople);
            System.out.println("  Cafeteria tables: " + numTables + " with " + numSeats + " seats each");
            System.out.println("Waiting for client connections...");

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Accepted connection from " + 
                                   clientSocket.getRemoteSocketAddress());
                
                // a new thread to handle client requests
                new _SubServerThread(clientSocket,
                                    class1,
                                    class2,
                                    cafeteria,
                                    officeHr,
                                    professor,
                                    timer)
                    .start();
            }
        } catch (IOException e) {
            System.err.println("Server error: " + e.getMessage());
            e.printStackTrace();
        }
    }
}