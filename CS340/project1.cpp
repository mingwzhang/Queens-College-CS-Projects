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
    int totalRemainingTime = 0; // Track total remaining time for all jobs

    float averageTurnaround = 0;
    float throughput = 0;

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.getArrTime() < b.getArrTime(); });

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

        // Calculate remaining time as the difference between turnaround time and CPU burst time
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

// Shortest Job First Algorithm (non-preemptive)
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

    cout << "SJF Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

// Shortest Remaining Time Algorithm
void srtScheduling(vector<Job> &jobs)
{
    int totalTurnaround = 0;
    int totalExitTime = 0;
    int currentTime = 0;
    int completedJobs = 0;

    // Copy remaining time of jobs to a separate vector
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
            if (jobs[i].getArrTime() <= currentTime && remainingTime[i] < shortestRemaining && remainingTime[i] > 0)
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

        // Execute the shortest remaining job for 1 time unit
        currentTime++;
        remainingTime[shortestRemainingIdx]--;

        // Check if the job has completed
        if (remainingTime[shortestRemainingIdx] == 0)
        {
            completedJobs++;
            jobs[shortestRemainingIdx].setExitTime(currentTime);
            int turnaroundTime = jobs[shortestRemainingIdx].getExitTime() - jobs[shortestRemainingIdx].getArrTime();
            jobs[shortestRemainingIdx].setTurnAroundTime(turnaroundTime);
            totalTurnaround += turnaroundTime;
            totalExitTime += jobs[shortestRemainingIdx].getExitTime();
        }
    }

    // Update the remaining time attribute for jobs with non-zero remaining burst time
    for (size_t i = 0; i < jobs.size(); ++i)
    {
        if (remainingTime[i] != 0)
        {
            jobs[i].setRemainingTime(remainingTime[i]);
        }
    }

    float averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    float throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "Shortest Remaining Time Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

// Highest Priority Algorithm
void highestPriorityScheduling(vector<Job> &jobs)
{
    int totalTurnaround = 0;
    int totalExitTime = 0;
    int currentTime = 0;
    int completedJobs = 0;

    // Sort jobs based on priority (higher priority first)
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.getPriority() > b.getPriority(); });

    // Copy remaining time of jobs to a separate vector
    vector<int> remainingTime(jobs.size());
    for (size_t i = 0; i < jobs.size(); ++i)
    {
        remainingTime[i] = jobs[i].getCpuBurst();
    }

    while (completedJobs < jobs.size())
    {
        // Find the highest priority job that has arrived and hasn't completed
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

        // Execute the highest priority job for 1 time unit
        currentTime++;
        remainingTime[highestPriorityIdx]--;

        // Check if the job has completed
        if (remainingTime[highestPriorityIdx] == 0)
        {
            completedJobs++;
            jobs[highestPriorityIdx].setExitTime(currentTime);
            int turnaroundTime = jobs[highestPriorityIdx].getExitTime() - jobs[highestPriorityIdx].getArrTime();
            jobs[highestPriorityIdx].setTurnAroundTime(turnaroundTime);

            // Correct the remaining time calculation here
            int remainingTimeCorrection = turnaroundTime - jobs[highestPriorityIdx].getCpuBurst();
            jobs[highestPriorityIdx].setRemainingTime(remainingTimeCorrection);

            totalTurnaround += turnaroundTime;
            totalExitTime += jobs[highestPriorityIdx].getExitTime();
        }
    }

    // Calculate average turnaround and throughput
    float averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    float throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "Highest Priority Scheduling Results:" << endl;
    printTable(jobs, averageTurnaround, throughput);
}

void rrScheduling(vector<Job> &jobs, int timeQuantum)
{
    int currentTime = 0;
    int completedJobs = 0;
    queue<int> jobQueue; // Queue to hold indices of jobs
    int quantumCount = 0; // Counter to track time quantum usage

    // Sort jobs based on arrival time initially
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
        return a.getArrTime() < b.getArrTime();
    });

    // Copy remaining time of jobs to a separate vector
    vector<int> remainingTime(jobs.size());
    for (size_t i = 0; i < jobs.size(); ++i)
    {
        remainingTime[i] = jobs[i].getCpuBurst();
    }

    while (completedJobs < jobs.size())
    {
        bool jobExecuted = false; // Flag to track if a job was executed in this cycle

        for (size_t i = 0; i < jobs.size(); ++i)
        {
            // Check if job has arrived and has remaining burst time
            if (jobs[i].getArrTime() <= currentTime && remainingTime[i] > 0)
            {
                jobQueue.push(i); // Add job index to the queue
            }
        }

        if (!jobQueue.empty())
        {
            int currentJobIdx = jobQueue.front(); // Get the front job from the queue
            jobQueue.pop(); // Remove the front job from the queue

            // Execute the job for 1 time unit or until its remaining time is exhausted
            int executeTime = min(timeQuantum, remainingTime[currentJobIdx]);
            currentTime += executeTime;
            remainingTime[currentJobIdx] -= executeTime;
            quantumCount += executeTime;
            jobExecuted = true; // Job was executed in this cycle

            // Check if the job has completed
            if (remainingTime[currentJobIdx] == 0)
            {
                completedJobs++;
                jobs[currentJobIdx].setExitTime(currentTime);
                int turnaroundTime = jobs[currentJobIdx].getExitTime() - jobs[currentJobIdx].getArrTime();
                jobs[currentJobIdx].setTurnAroundTime(turnaroundTime);

                // Correct the remaining time calculation here
                int remainingTimeCorrection = turnaroundTime - jobs[currentJobIdx].getCpuBurst();
                jobs[currentJobIdx].setRemainingTime(remainingTimeCorrection);
            }
            else
            {
                // If the job is not completed, re-add it to the end of the queue
                jobQueue.push(currentJobIdx);
            }
        }

        if (!jobExecuted)
        {
            currentTime++; // Increment time if no job was executed in this cycle
        }

if (quantumCount == timeQuantum && !jobExecuted && !jobQueue.empty())
{
    int currentJobIdx = jobQueue.front(); // Get the front job from the queue
    jobQueue.pop(); // Remove the front job from the queue
    jobQueue.push(currentJobIdx); // Re-add the job to the end of the queue
    quantumCount = 0; // Reset time quantum counter

    // Update exit time of the re-added job considering its previous execution cycles
    jobs[currentJobIdx].setExitTime(currentTime);
    currentTime += remainingTime[currentJobIdx]; // Increment current time by remaining time of the job
    remainingTime[currentJobIdx] = 0; // Set remaining time to 0 as the job completes
    int turnaroundTime = jobs[currentJobIdx].getExitTime() - jobs[currentJobIdx].getArrTime();
    jobs[currentJobIdx].setTurnAroundTime(turnaroundTime);
    // Correct the remaining time calculation here
    int remainingTimeCorrection = turnaroundTime - jobs[currentJobIdx].getCpuBurst();
    jobs[currentJobIdx].setRemainingTime(remainingTimeCorrection);
}

    }

    // Calculate average turnaround and throughput
    int totalTurnaround = 0;
    int totalExitTime = 0;
    for (size_t i = 0; i < jobs.size(); ++i)
    {
        totalTurnaround += jobs[i].getTurnAroundTime();
        totalExitTime += jobs[i].getExitTime();
    }
    float averageTurnaround = static_cast<float>(totalTurnaround) / jobs.size();
    float throughput = static_cast<float>(jobs.size()) / totalExitTime;

    cout << "Round Robin Scheduling Results:" << endl;
    // Replace priority values with "-"
    for (size_t i = 0; i < jobs.size(); ++i)
    {
        jobs[i].setPriority(0); // Set priority to 0
    }
    printTable(jobs, averageTurnaround, throughput);
}



void displayResult()
{
    srand(time(nullptr));

    int arrTime;
    int cpuBurst;
    int priority;
    //   int timeQuantum = (rand() % 2) + 1;
    int timeQuantum = 2;
    vector<Job> job;

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
    rrScheduling(job, timeQuantum);

    for (int x = 0; x < 5; x++)
    {
        cout << job[x].getArrTime() << " ";
    }
    cout << endl;
    for (int x = 0; x < 5; x++)
    {
        cout << job[x].getCpuBurst() << " ";
    }
}

int main()
{
    displayResult();    
    return 0;
}