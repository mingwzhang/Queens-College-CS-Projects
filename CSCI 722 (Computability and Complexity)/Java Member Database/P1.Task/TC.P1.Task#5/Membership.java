//Mingwei Zhang (23510667)

import java.io.*;
import java.util.*;

// Example usage:
// java Membership -firstname=Steve -lastname=Smith -id=1212121212 -age=28 -NewYork=true -outputFile=_output1.txt -inputFile=_inputMember.txt
// java Membership -id=1313131313 -age=30 -outputFile=_output2.txt -NewYork=false -lastname=Smith -firstname=Steve -inputFile=_inputMember.txt
// java Membership -NewYork=true -outputFile=_output3.txt -age=35 -firstname=Steve -id=1414141414 -lastname=Smith -inputFile=_inputMember.txt

public class Membership {
    // Hashtable to store members (ID as key, Member object as value)
    private static Hashtable<String, Member> members = new Hashtable<>();

    public static void main(String[] args) {
        String inputFile = null;
        String outputFile = null;
        Member newMember = new Member("", "", "", 0, false);
        boolean isDuplicate = false;

        // Parse command-line arguments (order-independent)
        for (String arg : args) {
            String[] parts = arg.split("=", 2);
            if (parts.length < 2) continue;
            
            switch (parts[0]) {
                case "-inputFile": inputFile = parts[1]; break;
                case "-outputFile": outputFile = parts[1]; break;
                case "-firstname": newMember.firstName = parts[1]; break;
                case "-lastname": newMember.lastName = parts[1]; break;
                case "-id": newMember.id = parts[1]; break;
                case "-age": newMember.age = Integer.parseInt(parts[1]); break;
                case "-NewYork": newMember.livesInNewYork = Boolean.parseBoolean(parts[1]); break;
            }
        }

        // Ensure input file is provided
        if (inputFile == null) {
            System.out.println("Error: No input file specified.");
            return;
        }

        // Ensure output file is provided, otherwise generate a new one
        if (outputFile == null) {
            outputFile = generateNextOutputFile();
        }

        // Check if input file exists
        File file = new File(inputFile);
        if (!file.exists()) {
            System.out.println("Error: Input file " + inputFile + " not found. Can't create output file.");
            return;
        }

        // Read the input file and store data in the hashtable
        readFile(inputFile);

        // Ensure new member details are complete
        if (newMember.id.isEmpty() || newMember.firstName.isEmpty() || newMember.lastName.isEmpty()) {
            System.out.println("Error: Incomplete member details.");
            return;
        }

        // Check if the member ID already exists
        if (members.containsKey(newMember.id)) {
            System.out.println("Error: Member with ID " + newMember.id + " already exists.");
            isDuplicate = true;
        } else {
            members.put(newMember.id, newMember);
        }
        
        // Write updated data to the specified output file
        createOutputFile(outputFile, isDuplicate, newMember);
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
     * Generates the next available output file name (output1.txt, output2.txt, etc.).
     */
    private static String generateNextOutputFile() {
        int count = 1;
        String fileName;
        do {
            fileName = "output" + count + ".txt";
            count++;
        } while (new File(fileName).exists());
        return fileName;
    }

    /**
     * Saves all members to an output file. If a duplicate ID was found, it adds an error message to the file.
     * @param fileName The name of the output file.
     * @param isDuplicate True if a duplicate ID was found, false otherwise.
     * @param newMember The new member being added (if unique).
     */
    private static void createOutputFile(String fileName, boolean isDuplicate, Member newMember) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileName))) {
            for (Member member : members.values()) {
                bw.write(member.firstName + "|" + member.lastName + "|" + member.id + "|" + member.age + "|" + member.livesInNewYork);
                bw.newLine();
            }
            
            // If a duplicate was found, add an error message to the file
            if (isDuplicate) {
                bw.write("Error: Member with ID " + newMember.id + " already exists.");
                bw.newLine();
            }
            
            System.out.println("Output file " + fileName + " created with updated member list.");
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }
}