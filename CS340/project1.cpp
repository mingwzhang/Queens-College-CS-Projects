using namespace std;
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>

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
    bool CompareRemainingTIme(Job job1, Job job2) { return job1.remainingTime < job2.remainingTime; }

    int getArrTime() const { return this->arrTime; }
    void setArrTime(int arrTime) { this->arrTime = arrTime; }

    int getCpuBurst() const { return this->cpuBurst; }
    void setCpuBurst(int cpuBurst) { this->cpuBurst = cpuBurst; }

    int getPriority() const { return this->priority; }
    void setPriority(int Priority) { this->priority = Priority; }

    int getExitTime() const { return this->exitTime; }
    void setExitTime(int exitTime) { this->exitTime = exitTime; }

    int getTurnAroundTime() const { return this->turnAroundTime; }
    void setTurnAroundTime(int turnAroundTime) { this->turnAroundTime = turnAroundTime; }

    int getRemainingTime() const { return this->remainingTime; }
    void setRemainingTime(int remainingTime) { this->remainingTime = remainingTime; }
};

void printTable(vector<Job> &jobs, float averageTurnAround, float throughput)
{
    cout << setw(5) << "Job #"
         << " | " << setw(15) << "Arrival Time"
         << " | " << setw(15)
         << "CPU Burst"
         << " | " << setw(15) << "Priority"
         << " | " << setw(15) << "Exit Time"
         << " | " << setw(15)
         << "Turnaround Time"
         << " | " << setw(15) << "Remaining Time"
         << " | " << endl;
    for (int i = 0; i < jobs.size(); ++i)
    {
        jobs[i].ToString(i + 1);
    }
    cout << endl;
    cout << "Average Turnaround: " << averageTurnAround << endl;
    cout << "Throughput: " << throughput << endl;
    cout << endl;
}

// FIFO
void fifoScheduling(vector<Job> &job)
{
    int totalTurnaround = 0;
    int totalExitTime = 0;

    float averageTurnaround = 0;
    float throughput = 0;
    
    sort(job.begin(), job.end(), [](const Job &a, const Job &b)
         { return a.getArrTime() < b.getArrTime(); });

    for (int i = 0; i < job.size(); ++i)
    {
        job[i].setPriority(job.size() - i);
    }

    for (auto &j : job)
    {
        j.setExitTime(j.getArrTime() + j.getCpuBurst());

        int turnaroundTime = (j.getExitTime() - j.getArrTime()) > 0 ? (j.getExitTime() - j.getArrTime()) : 0;
        j.setTurnAroundTime(turnaroundTime);
        totalTurnaround += j.getTurnAroundTime();

        totalExitTime += j.getExitTime();
    }

    averageTurnaround = totalTurnaround / 5.0;
    throughput = 5.0 / totalExitTime;
    cout << "FIFO Scheduling Results:" << endl;
    printTable(job, averageTurnaround, throughput);
}

// Shortest Job First Algorithm (non-preemptive)
void sjfNonPreemptiveScheduling(vector<Job> &job)
{
    float averageTurnaround = 0;
    float throughput = 0;

    sort(job.begin(), job.end(), [](const Job &a, const Job &b)
         {
             if (a.getCpuBurst() == b.getCpuBurst())
             {
                 return a.getArrTime() < b.getArrTime(); 
             }
             return a.getCpuBurst() < b.getCpuBurst(); });
    for (int i = 0; i < job.size(); ++i)
    {
        job[i].setPriority(job.size() - i);
    }
    int totalTurnaround = 0;
    int totalExitTime = 0;
    int currentTime = 0;
    int waitingTIme = 0;
    for (auto &j : job)
    {
        if(j.getPriority() < 5)
        {
            waitingTIme = currentTime - j.getArrTime();
        }
        currentTime = j.getArrTime() + j.getCpuBurst();
        j.setExitTime(currentTime);

        int turnaroundTime = (j.getExitTime() - j.getArrTime()) > 0 ? (j.getExitTime() - j.getArrTime()) : 0;
        j.setTurnAroundTime(turnaroundTime);
        totalTurnaround += turnaroundTime;

        totalExitTime += j.getExitTime();
    }
    averageTurnaround = static_cast<float>(totalTurnaround) / job.size();
    throughput = static_cast<float>(job.size()) / totalExitTime;

    cout << "SJF Scheduling Results:" << endl;
    printTable(job, averageTurnaround, throughput);
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
    srand(time(nullptr));

    int arrTime;
    int cpuBurst;
    int priority;
    vector<Job> job;

    for (int x = 1; x <= 5; x++)
    {
        arrTime = (rand() % 250) + 1;
        cpuBurst = (rand() % 14) + 2;
        priority = x;
        Job j(arrTime, cpuBurst, priority);
        job.push_back(j);
    }

    cout << endl<< endl;
    
    fifoScheduling(job);
    sjfNonPreemptiveScheduling(job);
}

int main()
{
    displayResult();
    return 0;
}