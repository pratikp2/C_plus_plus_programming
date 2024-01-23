// Non Preeemptive Approach

# include <iostream>
# include <unordered_set>
using namespace std;

# define NumberOfProcesses 4

int AvgWaitTime = 0;
int AvgTurnAroundTime = 0;
int Waiting_Time[NumberOfProcesses];
int TurnAround_Time[NumberOfProcesses];

void processBurstTime(int Burst_Time[],int Process[])
{

}

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

    processBurstTime(Burst_Time,Processes);
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
