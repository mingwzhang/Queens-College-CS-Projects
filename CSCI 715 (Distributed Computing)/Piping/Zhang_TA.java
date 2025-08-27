
import java.io.*;

public class Zhang_TA extends Thread {


   private InputStream fromTB;
   private ObjectInputStream fromTC;

   private OutputStream toTB;
   private ObjectOutputStream toTC;

   //Constructor 
   public Zhang_TA(InputStream fromTB, ObjectInputStream fromTC, OutputStream toTB, ObjectOutputStream toTC) {
      this.fromTB = fromTB;
      this.fromTC = fromTC;
      this.toTB = toTB;
      this.toTC = toTC;
   }

   public void run() {
      System.out.println("Thread A starting execution.");
      try {
         //Primitives objects
         DataOutputStream sendToTB = new DataOutputStream(toTB);
         DataInputStream inFromTB = new DataInputStream(fromTB);

         //TA sends primitive data to TB 
         int num = 42;
         sendToTB.writeInt(num);
         sendToTB.flush();
         System.out.println("TA sent primitive data to TB: " + num);
         
         //TA sends object data to TC 
         Zhang_Message messageC = new Zhang_Message(100);
         toTC.writeObject(messageC); 
         toTC.flush();
         System.out.println("TA sent object data to TC: " + messageC);

         //TA receives primitive data from TB 
         int receivedB = inFromTB.readInt();
         System.out.println("TA recieved message from TB: " + receivedB);

         //TA receives object data from TC 
         Object receivedC = fromTC.readObject();
         Zhang_Message replyC = (Zhang_Message) receivedC;
         System.out.println("TA recieved message from TC: " + replyC);

      } catch (Exception exc) {
         System.out.println("Error Receiver: " + exc);
      }

   }

}
