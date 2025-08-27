// Transition.java
public class Transition {
    public char writeChar;
    public char moveDirection; // 'L' or 'R'
    public String nextState;

    public Transition(char writeChar, char moveDirection, String nextState) {
        this.writeChar = writeChar;
        this.moveDirection = moveDirection;
        this.nextState = nextState;
    }
}
