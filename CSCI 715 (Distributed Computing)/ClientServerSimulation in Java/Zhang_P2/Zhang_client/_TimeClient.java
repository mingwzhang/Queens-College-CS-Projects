
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class _TimeClient extends Thread {
    // Number of concurrent Timer clients to launch
    private static final int numTimers = 1; 
    private static final int portNumber = 3000;
    private static final String address = "localhost";

    private static final int numMethods = 4; // set to actual count of Timer methods

    // Assign a unique name per client thread
    public _TimeClient(int id) {
        setName("Timer-" + id);
    }

    @Override
    public void run() {
        try (
            Socket socket = new Socket(address, portNumber);
            PrintWriter pw = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()))
        ) {
            // Sequentially invoke each Project 1 Timer method remotely
            for (int methodId = 0; methodId < numMethods; methodId++) {
                // Send: "Timer-<id> <methodId>"
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
        for (int i = 0; i < numTimers; i++) {
            new _TimeClient(i).start();
        }
    }
}
