
import java.io.*;

public class Zhang_TC extends Thread {
   private ObjectInputStream fromTA;

   private ObjectOutputStream toTA;
   private ObjectOutputStream toTB;

   public Zhang_TC(ObjectInputStream fromTA, ObjectOutputStream toTA, ObjectOutputStream toTB) {
      this.fromTA = fromTA;
      this.toTA = toTA;
      this.toTB = toTB;
   }

   public void run() {
      System.out.println("Thread C starting execution.");
      try {      

         //TC receives object data from TA   
         sleep(100);
         Zhang_Message receivedA = (Zhang_Message) fromTA.readObject();
         System.out.println("TC received object from TA: " + receivedA);

         //TC sends object data to TA   
         Zhang_Message messageA = new Zhang_Message(999);
         toTA.writeObject(messageA);
         toTA.flush();
         System.out.println("TC sent object data to TA: " + messageA);

         //TC sends object data to TB  
         Zhang_Message messageB = new Zhang_Message(888);
         toTB.writeObject(messageB);
         toTB.flush();
         System.out.println("TC sent object data to TB: " + messageB);

      } catch (Exception exc) {
         System.out.println("Error Receiver: " + exc);
      }

   }
}
