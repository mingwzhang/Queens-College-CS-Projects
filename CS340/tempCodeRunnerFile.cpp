void sjfNonPreemptiveScheduling(vector<Job> &jobs)
{
    float averageTurnaround = 0.0;
    float throughput = 0.0;

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