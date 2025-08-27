//Mingwei Zhang (23510667)

import java.io.*;
import java.util.*;

/**
 * Example input in Cmd command:
 * java Membership -firstname=Steve -lastname=Smith -id=1234567890 -age=23 -NewYork=false -outputFile=_output.txt -inputFile=_inputMember.txt
*/
public class Membership {
    // Hashtable to store members (ID as key, Member object as value)
    private static Hashtable<String, Member> members = new Hashtable<>();

    public static void main(String[] args) {
        String inputFile = null;
        String outputFile = null;
        Member newMember = null;

        // Loop through command-line arguments and assign values
        for (String arg : args) {
            if (arg.startsWith("-inputFile=")) inputFile = arg.split("=")[1];
            else if (arg.startsWith("-outputFile=")) outputFile = arg.split("=")[1];
            else if (arg.startsWith("-firstname=")) newMember = new Member(arg.split("=")[1], "", "", 0, false);
            else if (arg.startsWith("-lastname=")) newMember.lastName = arg.split("=")[1];
            else if (arg.startsWith("-id=")) newMember.id = arg.split("=")[1];
            else if (arg.startsWith("-age=")) newMember.age = Integer.parseInt(arg.split("=")[1]);
            else if (arg.startsWith("-NewYork=")) newMember.livesInNewYork = Boolean.parseBoolean(arg.split("=")[1]);
        }

        // Make sure an input file was given
        if (inputFile == null) {
            System.out.println("Error: Input file name not specified.");
            return;
        }

        // Check if the input file actually exists
        File file = new File(inputFile);
        if (!file.exists()) {
            System.out.println("Error: Input file " + inputFile + " not found. Output file will not be created.");
            return;
        }

        // Read the input file and store data in the hashtable
        readFile(inputFile);

        // Make sure we got all the necessary details for the new member
        if (newMember == null || newMember.id == null) {
            System.out.println("Error: New member details are incomplete.");
            return;
        }

        // Check if the member ID already exists
        if (members.containsKey(newMember.id)) {
            System.out.println("Error: Member with ID " + newMember.id + " already exists.");
            return;
        }

        // Add the new member since the ID is unique
        members.put(newMember.id, newMember);
        
        // If an output file was specified, write updated data to it
        if (outputFile != null) {
            createOutputFile(outputFile);
        }
    }

    /**
     * Reads an input file and adds members to the hashtable.
     * @param fileName The name of the input file.
     */
    private static void readFile(String fileName) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] data = line.split("\\|"); // Split by '|'
                if (data.length == 5) {
                    String firstName = data[0].trim();
                    String lastName = data[1].trim();
                    String id = data[2].trim();
                    int age = Integer.parseInt(data[3].trim());
                    boolean livesInNewYork = Boolean.parseBoolean(data[4].trim());
                    
                    members.put(id, new Member(firstName, lastName, id, age, livesInNewYork));
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    /**
     * Saves all members to an output file.
     * @param fileName The name of the output file.
     */
    private static void createOutputFile(String fileName) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileName))) {
            for (Member member : members.values()) {
                bw.write(member.firstName + "|" + member.lastName + "|" + member.id + "|" + member.age + "|" + member.livesInNewYork);
                bw.newLine();
            }
            System.out.println("Output file " + fileName + " created successfully with updated member list.");
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }
}
