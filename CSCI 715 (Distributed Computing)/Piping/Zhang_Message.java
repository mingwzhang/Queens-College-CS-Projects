import java.io.Serializable;

public class Zhang_Message implements Serializable {
    public int number;
    public int id = 67;

    public Zhang_Message(int number) { 
        this.number = number; 
    }

    public int getNumber(){return number;}
    public int getId(){return id;}

    @Override
    public String toString()
    {
        return "Number = " + number + ", ID = " + id;
    }

    
}