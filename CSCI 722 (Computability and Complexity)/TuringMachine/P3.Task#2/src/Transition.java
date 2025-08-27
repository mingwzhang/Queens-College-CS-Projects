// Transition.java
public class Transition {

    public char writeChar;  // symbol to write on the tape
    public char moveDirection; // 'L' or 'R'
    public String nextState; // state to switch to after this transition

    public Transition(char writeChar, char moveDirection, String nextState) {
        this.writeChar = writeChar;
        this.moveDirection = moveDirection;
        this.nextState = nextState;
    }
}
