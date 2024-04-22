using namespace std;
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>

class Job
{
protected:
    int arrTime;
    int cpuBurst;
    int priority;
    int exitTime;
    int turnAroundTime;
    int remainingTime;

public:
    Job(int a, int c, int p)
    {
        this->arrTime = a;
        this->cpuBurst = c;
        this->priority = p;
        this->exitTime = 0;
        this->turnAroundTime = 0;
        this->remainingTime = cpuBurst;
    }

    void ToString(int jobNum)
    {
        cout << setw(5) << jobNum << " | "
             << setw(15) << arrTime << " | "
             << setw(15) << cpuBurst << " | "
             << setw(15) << priority << " | " 
             << setw(15) << exitTime << " | " 
             << setw(15) << turnAroundTime << " | " 
             << setw(15) << remainingTime << " | " 
             << endl;
    }

    int CompareTo(Job job1, Job job2) { return job1.arrTime < job2.arrTime; } 
    int CompareRemainingTIme(Job job1, Job job2) { return job1.remainingTime < job2.remainingTime; }
    void calcuateTurnAroundTime(){ exitTime - arrTime; }

    int getArrTime() { return this->arrTime; }
    void setArrTime(int arrTime) { this->arrTime = arrTime; }

    int getCpuBurst() { return this->cpuBurst; }
    void setCpuBurst(int cpuBurst) { this->cpuBurst = cpuBurst; }

    int getPriority() { return this->priority; }
    void setPriority(int Priority) { this->priority = Priority; }

    int getExitTime() { return this->exitTime; }
    void setExitTime(int exitTime) { this->exitTime = exitTime; }

    int getTurnAroundTime() { return this->turnAroundTime; }
    void setTurnAroundTime(int turnAroundTime) { this->turnAroundTime = turnAroundTime; }

    int getRemainingTime() { return this->remainingTime; }
    void setRemainingTime(int remainingTime) { this->remainingTime = remainingTime; }
};

void printTable(vector<Job> & jobs)
{
    cout << setw (5) << "Job #"  << " | " << setw (15) << "Arrival Time"  << " | " << setw (15) 
         << "CPU Burst"  << " | " << setw (15) << "Priority"  << " | " << setw (15) << "Exit Time"  << " | " << setw (15) 
         << "Turnaround Time"  << " | " << setw (15) << "Remaining Time"  << " | " << endl;
    for (int i = 0; i < jobs.size(); ++i) {
        jobs[i].ToString(i + 1);
    }
}

// FIFO
void fifoScheduling(vector<Job>& jobs)
{
    int currentTime = 0;
    int turnAroundValue;
    int turnAroundResult;

    for(auto& job: jobs)
    {
        job.setExitTime(currentTime + job.getCpuBurst());
        currentTime = job.getExitTime();
        
        turnAroundValue = job.getExitTime() - job.getArrTime();
        turnAroundResult = turnAroundValue > 0 ? turnAroundValue: 0;
        job.setTurnAroundTime(turnAroundResult);
    }
    cout << "FIFO Scheduling Results:" << endl;
    printTable(jobs);
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

void displayResult()
{
    int arrTime;
    int cpuBurst;
    int priority;
    vector<Job> jobs;

    for (int x = 1; x <= 25; x++)
    {
        arrTime = (rand() % 250) + 1;
        cpuBurst = (rand() % 14) + 2;
        priority = (rand() % 5) + 1;
        Job j(arrTime, cpuBurst, priority);
        jobs.push_back(j);
    }
    
    cout << endl << endl;
    fifoScheduling(jobs);
}

int main()
{
    displayResult();
    srand(time(0));
    return 0;
}