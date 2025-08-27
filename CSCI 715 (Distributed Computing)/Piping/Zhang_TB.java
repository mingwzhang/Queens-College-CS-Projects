
import java.io.*;

public class Zhang_TB extends Thread {
   private InputStream fromTA;
   private ObjectInputStream fromTC;

   private OutputStream toTA;

   public Zhang_TB(InputStream fromTA, ObjectInputStream fromTC, OutputStream toTA) {
      this.fromTA = fromTA;
      this.fromTC = fromTC;
      this.toTA = toTA;
   }

   public void run() {
      System.out.println("Thread B starting execution.");
      try {

         //Primitives objects
         DataOutputStream sendToTA = new DataOutputStream(toTA);
         DataInputStream inFromTA = new DataInputStream(fromTA);

         //TB receives primitive data from TA 
         sleep(50);
         int recievedA = inFromTA.readInt();
         System.out.println("TB received message from TA: " + recievedA);

         //TB receives object data from TC 
         Zhang_Message messageC = (Zhang_Message) fromTC.readObject();
         System.out.println("TB received message from TC: " + messageC);

         //TB sends primitive data to TA 
         int resp = 202;
         sendToTA.writeInt(resp);
         sendToTA.flush();
         System.out.println("TB sent primitive data to TA: " + resp);
         
      } catch (Exception exc) {
         System.out.println("Error Receiver: " + exc);
      }

   }

}
