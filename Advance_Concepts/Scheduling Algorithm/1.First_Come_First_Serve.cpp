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

int Waiting_Time[NumberOfProcesses];
int Burst_Time[NumberOfProcesses];
int TurnAround_Time[NumberOfProcesses];
int Processes[NumberOfProcesses];

int main()
{
    Processes = {1,2,3,4};
    Burst_Time = {21,3,6,3};
    return 0;
}

// https://www.studytonight.com/operating-system/cpu-scheduling
