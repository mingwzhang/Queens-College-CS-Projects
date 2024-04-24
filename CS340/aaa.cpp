#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Job {
protected:
    int arrTime;  // Arrival time
    int cpuBurst;  // CPU time
    int priority;  // Priority (1-5)
    int exitTime;  // Algorithm result: exit time
    int turnAroundTime;  // Algorithm result: turnaround time
    int remainingTime;  // Updated in algorithms

public:
    // Constructor
    Job(int arr, int burst, int pri) : arrTime(arr), cpuBurst(burst), priority(pri), exitTime(-1), turnAroundTime(-1), remainingTime(burst) {}

    // Getter methods
    int getArrivalTime() const { return arrTime; }
    int getCPUBurst() const { return cpuBurst; }
    int getPriority() const { return priority; }
    int getExitTime() const { return exitTime; }
    int getTurnAroundTime() const { return turnAroundTime; }
    int getRemainingTime() const { return remainingTime; }

    // Setter methods
    void setExitTime(int time) { exitTime = time; }
    void setTurnAroundTime(int time) { turnAroundTime = time; }
    void setRemainingTime(int time) { remainingTime = time; }

    // Comparison method (for sorting)
    bool operator<(const Job& other) const {
        return arrTime < other.arrTime;
    }

    // ToString method
    string toString() const {
        return "Arrival Time: " + to_string(arrTime) + ", CPU Burst: " + to_string(cpuBurst) + ", Priority: " + to_string(priority) +
               ", Exit Time: " + to_string(exitTime) + ", Turnaround Time: " + to_string(turnAroundTime) + ", Remaining Time: " + to_string(remainingTime);
    }
};

// Function to compare jobs by priority (for Priority Algorithm)
bool comparePriority(const Job& job1, const Job& job2) {
    return job1.getPriority() > job2.getPriority();
}

// Function to simulate FIFO algorithm
void simulateFIFO(vector<Job>& jobs) {
    int currentTime = 0;
    for (auto& job : jobs) {
        job.setExitTime(currentTime + job.getCPUBurst());
        job.setTurnAroundTime(job.getExitTime() - job.getArrivalTime());
        currentTime = job.getExitTime();
    }
}

// Function to simulate SJF (Shortest Job First) algorithm (non-preemptive)
void simulateSJF(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), [](const Job& job1, const Job& job2) {
        return job1.getCPUBurst() < job2.getCPUBurst();
    });

    int currentTime = 0;
    for (auto& job : jobs) {
        job.setExitTime(currentTime + job.getCPUBurst());
        job.setTurnAroundTime(job.getExitTime() - job.getArrivalTime());
        currentTime = job.getExitTime();
    }
}

// Function to simulate SRJF (Shortest Remaining Job First) algorithm (preemptive)
void simulateSRJF(vector<Job>& jobs) {
    int currentTime = 0;
    while (!jobs.empty()) {
        auto shortest = min_element(jobs.begin(), jobs.end(), [](const Job& job1, const Job& job2) {
            return job1.getRemainingTime() < job2.getRemainingTime();
        });

        currentTime += shortest->getRemainingTime();
        shortest->setExitTime(currentTime);
        shortest->setTurnAroundTime(currentTime - shortest->getArrivalTime());
        jobs.erase(shortest);
    }
}

// Function to simulate Priority algorithm
void simulatePriority(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), comparePriority);

    int currentTime = 0;
    for (auto& job : jobs) {
        job.setExitTime(currentTime + job.getCPUBurst());
        job.setTurnAroundTime(job.getExitTime() - job.getArrivalTime());
        currentTime = job.getExitTime();
    }
}

// Function to simulate Round-Robin algorithm with a given time quantum
void simulateRoundRobin(vector<Job>& jobs, int timeQuantum) {
    int currentTime = 0;
    while (!jobs.empty()) {
        for (auto it = jobs.begin(); it != jobs.end();) {
            if (it->getRemainingTime() > timeQuantum) {
                currentTime += timeQuantum;
                it->setRemainingTime(it->getRemainingTime() - timeQuantum);
                ++it;
            } else {
                currentTime += it->getRemainingTime();
                it->setExitTime(currentTime);
                it->setTurnAroundTime(currentTime - it->getArrivalTime());
                it = jobs.erase(it);
            }
        }
    }
}

void printTable(const vector<Job>& jobs, const string& algorithmName) {
    cout << "Algorithm: " << algorithmName << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "| Job ID | Arrival Time | CPU Burst | Exit Time | Turnaround Time |" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (const auto& job : jobs) {
        cout << "|   " << "&i + 1 << "    |      " << job.getArrivalTime() << "       |     " << job.getCPUBurst() << "     |    " << job.getExitTime() << "    |        " << job.getTurnAroundTime() << "       |" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
}


int main() {
    // Generate 25 random jobs
    vector<Job> jobs;
    for (int i = 0; i < 25; ++i) {
        int arr = rand() % 250 + 1;
        int burst = rand() % 14 + 2;
        int pri = rand() % 5 + 1;
        jobs.emplace_back(arr, burst, pri);
    }

    // Sort jobs by arrival time
    sort(jobs.begin(), jobs.end());

    // Simulate algorithms
    simulateFIFO(jobs);
    printTable(jobs, "FIFO");

    simulateSJF(jobs);
    printTable(jobs, "Shortest Job First (SJF)");

    simulateSRJF(jobs);
    printTable(jobs, "Shortest Remaining Job First (SRJF)");

    simulatePriority(jobs);
    printTable(jobs, "Highest Priority");

    simulateRoundRobin(jobs, 5);
    printTable(jobs, "Round-Robin (Time Quantum: 5)");

    return 0;
}