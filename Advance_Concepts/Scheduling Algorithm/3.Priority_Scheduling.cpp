/** **********************************************************************************************************************
 *
 *  1. Priority is assigned for each process.
 *  2. Process with highest priority is executed first and so on.
 *  3. Processes with same priority are executed in FCFS manner.
 *  4. Priority can be decided based on memory requirements, time requirements or any other resource requirement.
 *
**************************************************************************************************************************/

# include <iostream>
using namespace std;

# define NumberOfProcesses 4

int AvgWaitTime = 0;
int AvgTurnAroundTime = 0;
int Waiting_Time[NumberOfProcesses];
int TurnAround_Time[NumberOfProcesses];
int Processed_Burst_Time[NumberOfProcesses];

void processPriority(int Priority[],int Burst_Time[],int Process[])
{
    for(int i=0; i<NumberOfProcesses; i++)
    {
        for(int j=0; j<NumberOfProcesses; j++)
        {
            if(i+1 == Priority[j])
            {
                Processed_Burst_Time[i] = Burst_Time[j];
                Process[i] = j+1;
            }
        }
        cout <<endl;
    }
}

void findWaitingTime()
{
    Waiting_Time[0] = 0;
    for (int i=1; i<NumberOfProcesses; i++)
    {
        Waiting_Time[i] = Waiting_Time[i-1] + Processed_Burst_Time[i-1];
    }
}

void findTurnAroundTime()
{
    for (int i=0; i<NumberOfProcesses; i++)
    {
        TurnAround_Time[i] = Waiting_Time[i] + Processed_Burst_Time[i];
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
    int Priority[NumberOfProcesses] = {2,1,4,3};

    processPriority(Priority,Burst_Time,Processes);
    findWaitingTime();
    findTurnAroundTime();
    findAverageTime();

    cout << "Process    "<< "Priority   "<< "Burst Time    " << "Processed Burst Time      "<< "Waiting Time      " << "Turn Around Time" <<endl <<endl;
    for(int i=0; i<NumberOfProcesses; i++)
    {
        cout << "   " <<Processes[i] << "\t      " <<Priority[i] << "\t          "<< Burst_Time[i] << "\t\t  "<< Processed_Burst_Time[i] << "\t\t\t  " << Waiting_Time[i] << "\t\t  " << TurnAround_Time[i] << endl;
    }

    cout <<"Average Waiting Time is     : "<< (float)AvgWaitTime/(float)NumberOfProcesses <<endl;
    cout <<"Average Turn around Time is : "<< (float)AvgTurnAroundTime/(float)NumberOfProcesses <<endl<<endl;

    return 0;
}

// https://www.studytonight.com/operating-system/introduction-operating-systems
