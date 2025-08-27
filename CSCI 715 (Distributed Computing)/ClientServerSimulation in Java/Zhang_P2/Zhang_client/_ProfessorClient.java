
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class _ProfessorClient extends Thread {
    private static final int numProfessors = 1; // adjust as needed
    private static final int portNumber = 3000;
    private static final String address = "localhost";

    private static final int numMethods = 3; // set to actual count of methods

    // Assign a unique name per client thread
    public _ProfessorClient(int id) {
        setName("Professor-" + id);
    }

    @Override
    public void run() {
        try (
            Socket socket = new Socket(address, portNumber);
            PrintWriter pw = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()))
        ) {
            // Sequentially invoke each Project 1 Professor method remotely
            for (int methodId = 0; methodId < numMethods; methodId++) {
                // Send: "Professor-<id> <methodId>"
                pw.println(getName() + " " + methodId);

                // Optional: read back server acknowledgment
                String response = br.readLine();
                if (response != null) {
                    System.out.println(response);
                }

                // Small pause between calls (optional)
                Thread.sleep(50);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        // Launch multiple _ProfessorClient threads if desired
        for (int i = 0; i < numProfessors; i++) {
            new _ProfessorClient(i).start();
        }
    }
}
