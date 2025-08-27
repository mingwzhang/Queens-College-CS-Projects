
public class _ClientLauncher {
    public static void main(String[] args) {
        // Launch all clients concurrently
        new Thread(new _ProfessorClient(0)).start();
        new Thread(new _TimeClient(0)).start();
        
        // Launch 20 students
        for (int i = 0; i < 20; i++) {
            new Thread(new _StudentClient(i)).start();
        }
    }
}