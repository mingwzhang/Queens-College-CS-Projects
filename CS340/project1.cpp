using namespace std;
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <climits>
#include <queue>

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
void fifoScheduling(vector<Job> &jobs)
{
    int totalTurnaround = 0;
    int totalExitTime = 0;

    float averageTurnaround = 0;
    float throughput = 0;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.getArrTime() < b.getArrTime(); });

    for (int i = 0; i < jobs.size(); ++i)
    {
        jobs[i].setPriority(jobs.size() - i);
    }

    for (auto &j : jobs)
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
    printTable(jobs, averageTurnaround, throughput);
}

// Shortest Job First Algorithm (non-preemptive)
void sjfNonPreemptiveScheduling(vector<Job> &jobs)
{
    float averageTurnaround = 0;
    float throughput = 0;

    int totalTurnaround = 0;
    int totalExitTime = 0;
    int currentTime = 0;
    int waitingTIme = 0;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         {
             if (a.getCpuBurst() == b.getCpuBurst())
             {
                 return a.getArrTime() < b.getArrTime(); 
             }
             return a.getCpuBurst() < b.getCpuBurst(); });
    for (int i = 0; i < jobs.size(); ++i)
    {
        jobs[i].setPriority(jobs.size() - i);
    }

    for (auto &j : jobs)
    {
        if (j.getPriority() < 5)
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
    averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "SJF Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

// Shortest Remaining Time Algorithm (preemptive)
void srtScheduling(vector<Job> &jobs)
{
    float averageTurnaround = 0;
    float throughput = 0;

    int totalTurnaround = 0;
    int totalExitTime = 0;
    int currentTime = 0;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
        return a.getArrTime() < b.getArrTime();
    });

    for (auto &j : jobs) {
        j.setRemainingTime(j.getCpuBurst());
    }

    int completedJobs = 0;
    int idx = 0; 

    while (completedJobs < jobs.size()) {
        int shortestRemainingTime = INT_MAX; 
        int shortestIdx = -1;

        for (int i = 0; i < jobs.size(); ++i) {
            if (jobs[i].getArrTime() <= currentTime && jobs[i].getRemainingTime() < shortestRemainingTime && jobs[i].getRemainingTime() > 0) {
                shortestRemainingTime = jobs[i].getRemainingTime();
                shortestIdx = i;
            }
        }

        if (shortestIdx == -1) {
            currentTime++;
            continue;
        }

        jobs[shortestIdx].setRemainingTime(jobs[shortestIdx].getRemainingTime() - 1);
        currentTime++;

        if (jobs[shortestIdx].getRemainingTime() == 0) {
            completedJobs++;
            jobs[shortestIdx].setExitTime(currentTime);
            int turnaroundTime = jobs[shortestIdx].getExitTime() - jobs[shortestIdx].getArrTime();
            jobs[shortestIdx].setTurnAroundTime(turnaroundTime);
            totalTurnaround += turnaroundTime;
            totalExitTime += jobs[shortestIdx].getExitTime();
        }
    }

    averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "Shortest Remaining Time (SRT) Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}


// Highest Priority Algorithm (assigned)
void highestPriorityScheduling(vector<Job> &jobs)
{
    float averageTurnaround = 0;
    float throughput = 0;

    int totalTurnaround = 0;
    int totalExitTime = 0;
    int currentTime = 0;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
        return a.getArrTime() < b.getArrTime();
    });

    for (auto &j : jobs) {
        j.setRemainingTime(j.getCpuBurst());
    }

    int completedJobs = 0;

    while (completedJobs < jobs.size()) {
        int highestPriorityIdx = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < jobs.size(); ++i) {
            if (jobs[i].getArrTime() <= currentTime && jobs[i].getPriority() < highestPriority && jobs[i].getRemainingTime() > 0) {
                highestPriority = jobs[i].getPriority();
                highestPriorityIdx = i;
            }
        }

        if (highestPriorityIdx == -1) {
            currentTime++;
            continue;
        }

        jobs[highestPriorityIdx].setRemainingTime(jobs[highestPriorityIdx].getRemainingTime() - 1);
        currentTime++;

        if (jobs[highestPriorityIdx].getRemainingTime() == 0) {
            completedJobs++;
            jobs[highestPriorityIdx].setExitTime(currentTime);
            int turnaroundTime = jobs[highestPriorityIdx].getExitTime() - jobs[highestPriorityIdx].getArrTime();
            jobs[highestPriorityIdx].setTurnAroundTime(turnaroundTime);
            totalTurnaround += turnaroundTime;
            totalExitTime += jobs[highestPriorityIdx].getExitTime();
        }
    }

    averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "Highest Priority Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

void rrSchedulingWithContextSwitch(vector<Job>& jobs, int timeQuantum) {
    int currentTime = 0;
    int totalTurnaround = 0;
    int totalExitTime = 0;
    int completedJobs = 0;

    queue<Job> jobQueue;

    while (completedJobs < jobs.size()) {
        for (auto& job : jobs) {
            if (job.getArrTime() <= currentTime && job.getRemainingTime() > 0) {
                jobQueue.push(job);
            }
        }

        if (!jobQueue.empty()) {
            Job currentJob = jobQueue.front();
            jobQueue.pop();

            int executionTime = min(timeQuantum, currentJob.getRemainingTime());
            currentJob.setRemainingTime(currentJob.getRemainingTime() - executionTime);
            currentTime += executionTime;

            if (currentJob.getRemainingTime() > 0) {
                jobQueue.push(currentJob);
            } else {
                currentJob.setExitTime(currentTime);
                int turnaroundTime = currentJob.getExitTime() - currentJob.getArrTime();
                currentJob.setTurnAroundTime(turnaroundTime);
                totalTurnaround += turnaroundTime;
                totalExitTime += currentJob.getExitTime();
                completedJobs++;
            }
        } else {
            currentTime++;
        }
    }

    float averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    float throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "Round-Robin Scheduling (with Context Switch) Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}


void rrSchedulingWithoutContextSwitch(vector<Job>& jobs, int timeQuantum) {
    int currentTime = 0;
    int totalTurnaround = 0;
    int totalExitTime = 0;
    int completedJobs = 0;
    int nextJobIndex = 0;

    while (completedJobs < jobs.size()) {
        Job& currentJob = jobs[nextJobIndex];

        if (currentJob.getArrTime() <= currentTime && currentJob.getRemainingTime() > 0) {
            int executionTime = min(timeQuantum, currentJob.getRemainingTime());
            currentJob.setRemainingTime(currentJob.getRemainingTime() - executionTime);
            currentTime += executionTime;

            if (currentJob.getRemainingTime() == 0) {
                currentJob.setExitTime(currentTime);
                int turnaroundTime = currentJob.getExitTime() - currentJob.getArrTime();
                currentJob.setTurnAroundTime(turnaroundTime);
                totalTurnaround += turnaroundTime;
                totalExitTime += currentJob.getExitTime();
                completedJobs++;
            }
        } else {
            currentTime++;
        }
        nextJobIndex = (nextJobIndex + 1) % jobs.size(); 
    }
    float averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    float throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "Round-Robin Scheduling (without Context Switch) Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

void displayResult()
{
    srand(time(nullptr));

    int arrTime;
    int cpuBurst;
    int priority;
    vector<Job> job;
    int timeQuantum = 5;    

    for (int x = 1; x <= 5; x++)
    {
        arrTime = (rand() % 250) + 1;
        cpuBurst = (rand() % 14) + 2;
        priority = x;
        Job j(arrTime, cpuBurst, priority);
        job.push_back(j);
    }

    fifoScheduling(job);
    sjfNonPreemptiveScheduling(job);
    srtScheduling(job);
    highestPriorityScheduling(job);
    rrSchedulingWithContextSwitch(job, timeQuantum);
    rrSchedulingWithoutContextSwitch(job, timeQuantum);
}

int main()
{
    displayResult();
    return 0;
}