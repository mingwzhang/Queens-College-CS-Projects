
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

public class _SubServerThread extends Thread {
    private static final String STUDENT   = "Student";
    private static final String PROFESSOR = "Professor";
    private static final String TIMER     = "Timer";

    private final Socket socket;
    private final ClassroomMonitor class1;
    private final ClassroomMonitor class2;
    private final CafeteriaMonitor cafeteria;
    private final OfficeHoursMonitor officeHr;
    
    private Professor professor;
    private Timer timer;
    
    // Track student instances by ID
    private final Map<Integer, Student> students = new HashMap<>();

    public _SubServerThread(Socket socket,
                           ClassroomMonitor class1,
                           ClassroomMonitor class2,
                           CafeteriaMonitor cafeteria,
                           OfficeHoursMonitor officeHr,
                           Professor professor,  // Pass professor from main server
                           Timer timer) {        // Pass timer from main server
        this.socket = socket;
        this.class1 = class1;
        this.class2 = class2;
        this.cafeteria = cafeteria;
        this.officeHr = officeHr;
        this.professor = professor;
        this.timer = timer;
    }

    @Override
    public void run() {
        try (
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter pw = new PrintWriter(socket.getOutputStream(), true)
        ) {
            System.out.println("Client handler started for: " + socket.getRemoteSocketAddress());
            
            String request;
            while ((request = br.readLine()) != null) {
                System.out.println("Received request: " + request);
                String[] parts = request.split(" ");
                String clientType = parts[0].split("-")[0];
                int clientId = Integer.parseInt(parts[0].split("-")[1]);
                int methodId = Integer.parseInt(parts[1]);

                String response = processRequest(clientType, clientId, methodId);
                pw.println(response);
            }
        } catch (IOException e) {
            System.err.println("Client handling error: " + e.getMessage());
        } finally {
            try {
                socket.close();
                System.out.println("Client connection closed");
            } catch (IOException e) {
                System.err.println("Error closing socket: " + e.getMessage());
            }
        }
    }

    private String processRequest(String clientType, int clientId, int methodId) {
        try {
            switch (clientType) {
                case STUDENT:
                    return handleStudent(clientId, methodId);
                case PROFESSOR:
                    return handleProfessor(methodId);
                case TIMER:
                    return handleTimer(methodId);
                default:
                    return "ERROR: Unknown client type - " + clientType;
            }
        } catch (Exception e) {
            return "ERROR: " + e.getMessage();
        }
    }

    private String handleStudent(int id, int methodId) {
        // Create student instance if it doesn't exist
        if (!students.containsKey(id)) {
            students.put(id, new Student(id, class1, class2, cafeteria, officeHr));
        }
        
        Student student = students.get(id);
        try {
            switch (methodId) {
                case 0:
                    student.toClass1Monitor();
                    return "Student-" + id + " entered class1";
                case 1:
                    student.toCafeteriaAfterClass();
                    return "Student-" + id + " went to cafeteria";
                case 2:
                    student.toClass2Monitor();
                    return "Student-" + id + " entered class2";
                case 3:
                    student.toOfficeHourMonitor();
                    return "Student-" + id + " joined office hour queue";
                default:
                    return "ERROR: Invalid method ID for Student";
            }
        } catch (Throwable t) {
            return "ERROR in Student method " + methodId + ": " + t.getMessage();
        }
    }

    private String handleProfessor(int methodId) {
        if (professor == null) {
            return "ERROR: Professor not initialized";
        }
        
        try {
            switch (methodId) {
                case 0:
                    professor.toClass1Monitor();
                    return "Professor started class1";
                case 1:
                    professor.toClass2Monitor();
                    return "Professor started class2";
                case 2:
                    professor.toOfficeHourMonitor();
                    return "Professor started office hours";
                default:
                    return "ERROR: Invalid method ID for Professor";
            }
        } catch (Throwable t) {
            return "ERROR in Professor method " + methodId + ": " + t.getMessage();
        }
    }

    private String handleTimer(int methodId) {
        if (timer == null) {
            return "ERROR: Timer not initialized";
        }
        
        try {
            switch (methodId) {
                case 0:
                    timer.Class1Event();
                    return "Timer triggered Class1Event";
                case 1:
                    timer.CafeteriaEvent();
                    return "Timer triggered CafeteriaEvent";
                case 2:
                    timer.Class2Event();
                    return "Timer triggered Class2Event";
                case 3:
                    timer.OfficeHourEvent();
                    return "Timer triggered OfficeHourEvent";
                default:
                    return "ERROR: Invalid method ID for Timer";
            }
        } catch (Throwable t) {
            return "ERROR in Timer method " + methodId + ": " + t.getMessage();
        }
    }
}