#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int exitTime;
};

void roundRobinScheduling(vector<Process>& processes, int timeQuantum) {
    queue<Process> readyQueue;
    int currentTime = 0;
    int completed = 0;

    while (completed < processes.size()) {
        for (auto& process : processes) {
            if (process.arrivalTime <= currentTime && process.remainingTime > 0) {
                readyQueue.push(process);
            }
        }

        if (readyQueue.empty()) {
            currentTime++;
        } else {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();

            int executionTime = min(timeQuantum, currentProcess.remainingTime);
            currentTime += executionTime;
            currentProcess.remainingTime -= executionTime;

            if (currentProcess.remainingTime <= 0) {
                currentProcess.exitTime = currentTime;
                completed++;
            } else {
                readyQueue.push(currentProcess);
            }
        }
    }
}

int main() {
    vector<Process> processes = {
        {1, 0, 5, 5, 0},  // id, arrivalTime, burstTime, remainingTime, exitTime
        {2, 1, 3, 3, 0},
        {3, 2, 8, 8, 0},
        {4, 3, 6, 6, 0}
    };

    int timeQuantum = 2;

    roundRobinScheduling(processes, timeQuantum);

    // Display the exit time for each process
    for (const auto& process : processes) {
        cout << "Process " << process.id << " exited at time " << process.exitTime << endl;
    }

    return 0;
}
