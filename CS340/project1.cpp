using namespace std;
#include <iostream>
#include <vector>

class Job {
protected:
    int arrTime;
    int cpuBurst;
    int Priority;
    int exitTime;
    int turnAroundTime;
    int remainingTime;

public:
    Job(int a, int c, int p)
    {
        this->arrTime = a;
        this->cpuBurst = c;
        this->Priority = p;
        this->exitTime = 0;
        this->turnAroundTime = 0;
        this->remainingTime = 0;
    }

    void set(int s) {}

    void ToString()
    {
        cout << "Arrival Time: " << arrTime << " | CPU Burst: " << cpuBurst
             << " | Priority: " << Priority << " | Remaining Time: " << remainingTime;
    }

    int CompareTo(int arrivalTime)
    {
        return 0;
    }

    void calcuateTurnAroundTime()
    {
        exitTime - arrTime;
    }

    int getArrTime() { return this->arrTime; }
    void setArrTime(int arrTime) { this->arrTime = arrTime; }

    int getCpuBurst() { return this->cpuBurst; }
    void setCpuBurst(int cpuBurst) { this->cpuBurst = cpuBurst; }

    int getPriority() { return this->Priority; }
    void setPriority(int Priority) { this->Priority = Priority; }

    int getExitTime() { return this->exitTime; }
    void setExitTime(int exitTime) { this->exitTime = exitTime; }

    int getTurnAroundTime() { return this->turnAroundTime; }
    void setTurnAroundTime(int turnAroundTime) { this->turnAroundTime = turnAroundTime; }

    int getRemainingTime() { return this->remainingTime; }
    void setRemainingTime(int remainingTime) { this->remainingTime = remainingTime; }
};

// FIFO
void fifoScheduling()
{

}

// Shortest Job First Algorithm (non-preemptive)
void sjfNonPreemptiveScheduling()
{

}

// Shortest Remaining Job Algorithm (preemptive)
void sjfPreemptiveScheduling()
{

}

// Highest Priority Algorithm (assigned)
void highestPriorityScheduling()
{

}

// Round-Robin: with context switch
void rrWithContextSwitch()
{

}

// Round-Robin: without context switch
void rrWithoutContextSwitch()
{

}

int main()
{
    Job j (1,2,3);
    j.ToString();
}