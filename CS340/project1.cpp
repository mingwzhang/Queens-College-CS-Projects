// Mingwei Zhang
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
        this->remainingTime = 0;
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

    bool CompareTo(const Job &other) const
    {
        return this->arrTime < other.arrTime;
    }
    bool CompareRemainingTime(const Job &other) const
    {
        return this->remainingTime < other.remainingTime;
    }

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FIFO
void fifoScheduling(vector<Job> &jobs)
{
    int totalTurnaround = 0;
    int totalRemainingTime = 0;

    float averageTurnaround = 0;
    float throughput = 0;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.CompareTo(b); });

    for (int i = 0; i < jobs.size(); ++i)
    {
        jobs[i].setPriority(jobs.size() - i);
    }

    for (int i = 0; i < jobs.size(); ++i)
    {
        if (i == 0 || jobs[i].getArrTime() >= jobs[i - 1].getExitTime())
        {
            jobs[i].setExitTime(jobs[i].getArrTime() + jobs[i].getCpuBurst());
        }
        else
        {
            jobs[i].setExitTime(jobs[i - 1].getExitTime() + jobs[i].getCpuBurst());
        }

        int turnaroundTime = jobs[i].getExitTime() - jobs[i].getArrTime();
        jobs[i].setTurnAroundTime(turnaroundTime);

        int remainingTime = turnaroundTime - jobs[i].getCpuBurst();
        jobs[i].setRemainingTime(remainingTime);
        totalRemainingTime += remainingTime;

        totalTurnaround += turnaroundTime;
    }

    averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    throughput = static_cast<float>(jobs.size()) / jobs.back().getExitTime();

    cout << "FIFO Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Shortest Job First Algorithm
void sjfNonPreemptiveScheduling(vector<Job> &jobs)
{
    float averageTurnaround = 0.0;
    float throughput = 0.0;

    int totalTurnaround = 0;
    int totalExitTime = 0;
    int currentTime = 0;
    int remainingTime = 0;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         {
        if (a.getCpuBurst() == b.getCpuBurst()) {
            return a.CompareTo(b); 
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
            remainingTime = currentTime - j.getArrTime();
        }
        currentTime = j.getArrTime() + j.getCpuBurst();
        j.setExitTime(currentTime);

        int turnaroundTime = (j.getExitTime() - j.getArrTime()) + j.getRemainingTime();
        j.setTurnAroundTime(turnaroundTime);
        totalTurnaround += turnaroundTime;

        totalExitTime += j.getExitTime();
    }
    averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "SJF (Non-preemptive) Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Shortest Remaining Job Algorithm (SRT)
void srtScheduling(vector<Job> &jobs)
{
    int totalTurnaround = 0;
    int totalExitTime = 0;
    int currentTime = 0;
    int completedJobs = 0;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.CompareTo(b); });

    vector<int> remainingTime(jobs.size());
    for (size_t i = 0; i < jobs.size(); ++i)
    {
        remainingTime[i] = jobs[i].getCpuBurst();
    }

    while (completedJobs < jobs.size())
    {
        int shortestRemainingIdx = -1;
        int shortestRemaining = INT_MAX;
        for (size_t i = 0; i < jobs.size(); ++i)
        {
            if (jobs[i].getArrTime() <= currentTime && remainingTime[i] > 0 &&
                (shortestRemainingIdx == -1 || jobs[i].CompareRemainingTime(jobs[shortestRemainingIdx])))
            {
                shortestRemaining = remainingTime[i];
                shortestRemainingIdx = i;
            }
        }

        if (shortestRemainingIdx == -1)
        {
            currentTime++;
            continue;
        }

        currentTime++;

        remainingTime[shortestRemainingIdx]--;

        if (remainingTime[shortestRemainingIdx] == 0)
        {
            completedJobs++;

            jobs[shortestRemainingIdx].setExitTime(currentTime);
            int turnaroundTime = jobs[shortestRemainingIdx].getExitTime() - jobs[shortestRemainingIdx].getArrTime();
            jobs[shortestRemainingIdx].setTurnAroundTime(turnaroundTime);

            int remainingTimeCorrection = turnaroundTime - jobs[shortestRemainingIdx].getCpuBurst();
            jobs[shortestRemainingIdx].setRemainingTime(max(remainingTimeCorrection, 0));

            totalTurnaround += turnaroundTime;
            totalExitTime += jobs[shortestRemainingIdx].getExitTime();
        }

        for (size_t i = 0; i < jobs.size(); ++i)
        {
            if (jobs[i].getArrTime() <= currentTime && remainingTime[i] > 0 && i != shortestRemainingIdx)
            {
                jobs[i].setRemainingTime(remainingTime[i]);
            }
        }
    }

    float averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    float throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "Shortest Remaining Time Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Highest Priority Algorithm
void highestPriorityScheduling(vector<Job> &jobs)
{
    int totalTurnaround = 0;
    int totalExitTime = 0;
    int currentTime = 0;
    int completedJobs = 0;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.getPriority() > b.getPriority(); });

    vector<int> remainingTime(jobs.size());
    for (size_t i = 0; i < jobs.size(); ++i)
    {
        remainingTime[i] = jobs[i].getCpuBurst();
    }

    while (completedJobs < jobs.size())
    {
        int highestPriorityIdx = -1;
        int highestPriority = INT_MAX;

        for (size_t i = 0; i < jobs.size(); ++i)
        {
            if (jobs[i].getArrTime() <= currentTime && jobs[i].getPriority() < highestPriority && remainingTime[i] > 0)
            {
                highestPriority = jobs[i].getPriority();
                highestPriorityIdx = i;
            }
        }

        if (highestPriorityIdx == -1)
        {
            currentTime++;
            continue;
        }

        currentTime++;
        remainingTime[highestPriorityIdx]--;

        if (remainingTime[highestPriorityIdx] == 0)
        {
            completedJobs++;
            jobs[highestPriorityIdx].setExitTime(currentTime);
            int turnaroundTime = jobs[highestPriorityIdx].getExitTime() - jobs[highestPriorityIdx].getArrTime();
            jobs[highestPriorityIdx].setTurnAroundTime(turnaroundTime);

            int remainingTimeCorrection = turnaroundTime - jobs[highestPriorityIdx].getCpuBurst();
            jobs[highestPriorityIdx].setRemainingTime(remainingTimeCorrection);

            totalTurnaround += turnaroundTime;
            totalExitTime += jobs[highestPriorityIdx].getExitTime();
        }
    }

    float averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    float throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "Highest Priority Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Round Robin Algorithm
void rrScheduling(vector<Job> &jobs)
{
    int currentTime = 0;
    int completedJobs = 0;

    int timeQuantum = (rand() % 3) + 1;
    int contextSwitch = (rand() % 2) + 1;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.getArrTime() < b.getArrTime(); });

    vector<int> remainingTime(jobs.size());
    for (size_t i = 0; i < jobs.size(); ++i)
    {
        remainingTime[i] = jobs[i].getCpuBurst();
    }

    queue<int> readyQueue;

    while (completedJobs < jobs.size())
    {
        for (size_t i = 0; i < jobs.size(); ++i)
        {
            if (jobs[i].getArrTime() <= currentTime && remainingTime[i] > 0)
            {
                readyQueue.push(i);
            }
        }

        if (!readyQueue.empty())
        {
            int currentJobIdx = readyQueue.front();
            readyQueue.pop();

            int executionTime = min(executionTime + contextSwitch, remainingTime[currentJobIdx]);

            currentTime += executionTime;
            remainingTime[currentJobIdx] -= executionTime;

            if (remainingTime[currentJobIdx] == 0)
            {
                completedJobs++;
                jobs[currentJobIdx].setExitTime(currentTime);
                int turnaroundTime = jobs[currentJobIdx].getExitTime() - jobs[currentJobIdx].getArrTime();
                jobs[currentJobIdx].setTurnAroundTime(turnaroundTime);

                int remainingTimeCorrection = turnaroundTime - jobs[currentJobIdx].getCpuBurst();
                jobs[currentJobIdx].setRemainingTime(remainingTimeCorrection);
            }
            else
            {
                readyQueue.push(currentJobIdx);
            }
        }
        else
        {
            currentTime++;
        }
    }
    int totalTurnaround = 0;
    int totalExitTime = 0;
    for (size_t i = 0; i < jobs.size(); ++i)
    {
        totalTurnaround += jobs[i].getTurnAroundTime();
        totalExitTime += jobs[i].getExitTime();
    }
    float averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    float throughput = static_cast<float>(jobs.size()) / totalExitTime;

    for (auto &job : jobs)
    {
        job.setPriority(1);
    }

    cout << "Round Robin Scheduling Results (Time Quantum = " << timeQuantum << ", Context Switch = " << contextSwitch << "):" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

void displayResult()
{
    srand(time(nullptr));

    int arrTime;
    int cpuBurst;
    int priority;

    vector<Job> job;

    for (int x = 1; x <= 25; x++)
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
    rrScheduling(job);

/*
    for (int x = 0; x < 25; x++)
    {
        cout << job[x].getArrTime() << " ";
    }
    cout << endl;
    for (int x = 0; x < 25; x++)
    {
        cout << job[x].getCpuBurst() << " ";
    }
*/
}

int main()
{
    displayResult();
    return 0;
}