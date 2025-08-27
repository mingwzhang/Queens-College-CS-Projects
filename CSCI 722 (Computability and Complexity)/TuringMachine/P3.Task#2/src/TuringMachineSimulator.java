// TuringMachineSimulator.java
import java.io.*;
import java.util.*;

public class TuringMachineSimulator {
    private static Map<String, Transition> transitionMap = new HashMap<>();
    private static List<Character> tape = new ArrayList<>();     // Dynamic list representing the tape
    private static int head = 0; // current tape head position
    private static String currentState = null; // will be set from first transition
    private static int maxSteps; // maximum steps before forced halt

    public static void main(String[] args) throws Exception {
        String transitionsFile = "../data/TransitionsFile.txt";
        String inputFile = "../data/InitialTapeInput.txt";
        String outputFile = "../data/FinalOutput.txt";
        maxSteps = 1000; // default limit to avoid infinite loops

        PrintWriter out = new PrintWriter(outputFile);
        if (maxSteps == 0) { 
            out.println("TransitionsFile: " + transitionsFile);
            out.println("InitialTapeInput: " + inputFile);
            out.close();
            return;
        }

        loadTransitions(transitionsFile);
        loadTape(inputFile);

        int steps = 0;
        boolean halted = false;

        while (steps < maxSteps) { // main loop
            String key = currentState + tape.get(head);
            if (!transitionMap.containsKey(key)) {
                halted = true;
                break;
            }
            Transition t = transitionMap.get(key);
            tape.set(head, t.writeChar);
            head += (t.moveDirection == 'R' ? 1 : -1);
            if (head < 0) {
                tape.add(0, '_'); // blank symbol
                head = 0;
            } else if (head >= tape.size()) {
                tape.add('_');
            }
            currentState = t.nextState;
            steps++;
        }

        //output final tape, halt status, and steps used
        for (char c : tape) out.print(c);
        out.println();
        out.println("Halted: " + halted);
        out.println("Steps used: " + steps);
        out.close();
    }

    // load transitions from file, skip malformed lines, and set start state
    private static void loadTransitions(String file) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(file));
        String line;
        boolean firstLine = true;

        while ((line = br.readLine()) != null) {
            String[] parts = line.split("\\s+");
            if (parts.length < 5) continue; // skip malformed lines
            String key = parts[0] + parts[1];
            transitionMap.put(key, new Transition(parts[2].charAt(0), parts[3].charAt(0), parts[4])); // writeChar. moveDirection, nextState
            
            if (firstLine) {
                currentState = parts[0]; // use first state's name as start state
                firstLine = false;
            }
        }
        br.close();
    }

    // read tape contents from input file into the list
    private static void loadTape(String file) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(file));
        String line = br.readLine();
        for (char c : line.toCharArray()) tape.add(c);
        br.close();
    }
}
