
// Mingwei Zhang

// Monitor to coordinate office hour access and question answering

import java.util.*;

public class OfficeHoursMonitor 
{
    private Queue<String> line = new LinkedList<>(); // student question line
    private boolean lineUpReady = false;  // true if students can start lining up

    private Object sessionEndBlock = new Object(); // used to notify end of office hour
    public int studentDecisionNum = 0; // count of students decisions

    //constructor
    public OfficeHoursMonitor() {
    }

    // returns true if all students finished deciding to stay or leave
    public boolean finishWaiting() {
        return studentDecisionNum == 0; 
    }

    // blocks student until office hour opens, then checks if they want to join
    public synchronized Boolean joinOfficeHour(String student, int randomNum) throws InterruptedException
    {        
        while(!lineUpReady) wait();
        if(randomNum < 4)  // 1-3 joins, 4-10 skips
        {
            line.add(student); // student gets in line
            return true;
        }
        return false;
    }

    // triggered by timer thread to open lineup
    public synchronized void prepareOfficeHour() 
    {
        lineUpReady = true;
        notifyAll(); // wake all students waiting to decide
    }

    // return number of students in line
    public int studentNumInLine()
    {
        return line.size();
    }

    // return and remove next student in line
    public String nexStudent()
    {
        return line.poll();
    }

    // professor blocks until all students finish their decision
    public synchronized void waitForAllDecisions() throws InterruptedException {
        while (studentDecisionNum > 0) {
            wait();     
        }
    }

    // professor wakes up student after answering question
    public synchronized void studentQuestionAnswered(Student student) {
            student.notify();
    }

    // student calls this if they intend to make a decision
    public synchronized void addStudentCount() {
        studentDecisionNum++;
    }

    // used to release all remaining students after session ends
    public synchronized void endSession() {
            sessionEndBlock.notifyAll();
    }

    //wakes up professor every time student decision is checked
    public synchronized void registeredStudentDecision(){ 
        studentDecisionNum--;
        notifyAll();  
    }
}