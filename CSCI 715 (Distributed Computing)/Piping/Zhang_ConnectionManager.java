
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Zhang_ConnectionManager {
    public static void main(String args[]) {
        try {
            //Set up pipe
            System.out.println("Pipe setup");

            //TA to TB (primitive)
            PipedOutputStream pos_TA_to_TB = new PipedOutputStream();  
            PipedInputStream pis_TB_from_TA = new PipedInputStream(pos_TA_to_TB);

            //TB to TA (primitive)
            PipedOutputStream pos_TB_to_TA = new PipedOutputStream();
            PipedInputStream pis_TA_from_TB = new PipedInputStream(pos_TB_to_TA);
            
            //TA to TC (object)
            PipedOutputStream pos_TA_to_TC = new PipedOutputStream();  
            PipedInputStream pis_TC_from_TA = new PipedInputStream(pos_TA_to_TC); 
            ObjectOutputStream oos_TA_to_TC = new ObjectOutputStream(pos_TA_to_TC);
            ObjectInputStream ois_TC_from_TA = new ObjectInputStream(pis_TC_from_TA);  

            //TC to TA (object)
            PipedOutputStream pos_TC_to_TA = new PipedOutputStream();
            PipedInputStream pis_TA_from_TC = new PipedInputStream(pos_TC_to_TA);
            ObjectOutputStream oos_TC_to_TA = new ObjectOutputStream(pos_TC_to_TA);
            ObjectInputStream ois_TA_from_TC = new ObjectInputStream(pis_TA_from_TC);
            
            //TC to TB (object)
            PipedOutputStream pos_TC_to_TB = new PipedOutputStream();
            PipedInputStream pis_TB_from_TC = new PipedInputStream(pos_TC_to_TB);
            ObjectOutputStream oos_TC_to_TB = new ObjectOutputStream(pos_TC_to_TB);
            ObjectInputStream ois_TB_from_TC = new ObjectInputStream(pis_TB_from_TC);
            
            //Instantiate each thread object with its appropriate pipes
            Zhang_TA ta = new Zhang_TA(pis_TA_from_TB, ois_TA_from_TC, pos_TA_to_TB, oos_TA_to_TC);
            Zhang_TB tb = new Zhang_TB(pis_TB_from_TA, ois_TB_from_TC, pos_TB_to_TA);
            Zhang_TC tc = new Zhang_TC(ois_TC_from_TA, oos_TC_to_TA, oos_TC_to_TB);


            //Thread execution
            ta.start();
            tb.start();
            tc.start();

            //Prevents "broken pipe" or dead-end errors by ensuring every send/receive completes
            ta.join();
            tb.join();
            tc.join();
        } catch (Exception exc) {
            System.out.println(exc);
        }
    }

}
