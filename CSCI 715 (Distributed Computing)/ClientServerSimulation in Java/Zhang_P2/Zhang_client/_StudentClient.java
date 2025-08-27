
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class _StudentClient extends Thread {
    // Number of concurrent Student clients to launch
    private static final int numStudents = 1; // adjust as needed
    private static final int portNumber = 3000;
    private static final String address = "localhost";

    // Assign a unique name per client thread
    public _StudentClient(int id) {
        setName("Student-" + id);
    }

    @Override
    public void run() {
        try (
            Socket socket = new Socket(address, portNumber);
            PrintWriter pw = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()))
        ) {
            // Sequentially invoke the four Project 1 methods remotely
            for (int methodId = 0; methodId < 4; methodId++) {
                // Send: "Student-<id> <methodId>"
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
        for (int i = 0; i < numStudents; i++) {
            new _StudentClient(i).start();
        }
    }
}
