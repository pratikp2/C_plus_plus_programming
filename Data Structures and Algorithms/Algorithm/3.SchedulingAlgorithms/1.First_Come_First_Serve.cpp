/** **********************************************************************************************************************
 *
 *  Problems with FCFS Scheduling
 *
 *      1. It is Non Pre-emptive algorithm, which means the process priority doesn't matter.
 *         If a process with very least priority is being executed, more like daily routine backup process, which takes more time,
 *         and all of a sudden some other high priority process arrives, like interrupt to avoid system crash, the high priority
 *         process will have to wait, and hence in this case, the system will crash, just because of improper process scheduling.
 *
 *      2. Not optimal Average Waiting Time.
 *
 *      3. Resources utilization in parallel is not possible, which leads to Convoy Effect, and hence poor resource(CPU, I/O etc)
 *         utilization.
 *
 *      What is Convoy Effect?
 *      Convoy Effect is a situation where many processes, who need to use a resource for short time are blocked by one process
 *      holding that resource for a long time. This essentially leads to poort utilization of resources and hence poor performance.
 *
**************************************************************************************************************************/

# include <iostream>
using namespace std;

# define NumberOfProcesses 4

int AvgWaitTime = 0;
int AvgTurnAroundTime = 0;
int Waiting_Time[NumberOfProcesses];
int TurnAround_Time[NumberOfProcesses];

void findWaitingTime(int Burst_Time[])
{
    Waiting_Time[0] = 0;
    for (int i=1; i<NumberOfProcesses; i++)
    {
        Waiting_Time[i] = Waiting_Time[i-1] + Burst_Time[i-1];
    }
}

void findTurnAroundTime(int Burst_Time[])
{
    for (int i=0; i<NumberOfProcesses; i++)
    {
        TurnAround_Time[i] = Waiting_Time[i] + Burst_Time[i];
    }
}

void findAverageTime()
{
    for (int i=0; i<NumberOfProcesses; i++)
    {
        AvgWaitTime = AvgWaitTime + Waiting_Time[i];
        AvgTurnAroundTime = AvgTurnAroundTime + TurnAround_Time[i];
    }
}

int main()
{
    int Processes[NumberOfProcesses] = {1,2,3,4};
    int Burst_Time[NumberOfProcesses] = {21,3,6,2};

    findWaitingTime(Burst_Time);
    findTurnAroundTime(Burst_Time);
    findAverageTime();

    cout << "Process    " << "Burst Time    " << "Waiting Time      " << "Turn Around Time" <<endl <<endl;
    for(int i=0; i<NumberOfProcesses; i++)
    {
        cout << "   " <<1+i << "\t\t" << Burst_Time[i] << "\t\t" << Waiting_Time[i] << "\t\t" << TurnAround_Time[i] << endl;
    }

    cout <<"Average Waiting Time is     : "<< (float)AvgWaitTime/(float)NumberOfProcesses <<endl;
    cout <<"Average Turn around Time is : "<< (float)AvgTurnAroundTime/(float)NumberOfProcesses <<endl<<endl;

    return 0;
}
