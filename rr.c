#include<stdio.h>

typedef struct{
	int pid;
	int arrival;
	int burst;
	int remaining;
	int start;
	int finish;
	int turnaround;
	int wait;
	int completed;
} Process;

Process processes[20];

void sortOnArrivalTime(int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(processes[i].arrival > processes[j].arrival)
			{
				Process temp = processes[i];
				processes[i] = processes[j];
				processes[j] = temp;
			}
		}
		
	}
}

void sortOnPID(int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(processes[i].pid > processes[j].pid)
			{
				Process temp = processes[i];
				processes[i] = processes[j];
				processes[j] = temp;
			}
		}
		
	}
}

void calculateTimes(int n, int quantum)
{
	int currentTime = 0;
	int completedProcesses = 0;
	int i = 0;
	
	while(completedProcesses < n)
	{
		if(processes[i].remaining>0)
		{
			if(processes[i].remaining == processes[i].burst) 
			{
				processes[i].start = currentTime;
			}
			if(processes[i].remaining <= quantum)
			{
				currentTime += processes[i].remaining;
				processes[i].remaining = 0;
				processes[i].finish = currentTime;
				processes[i].completed = 1;
				processes[i].turnaround = processes[i].finish - processes[i].arrival;
				processes[i].wait = processes[i].turnaround - processes[i].burst;
				completedProcesses++;
			}
			else
			{
				processes[i].remaining -= quantum;
				currentTime += quantum;
			}
		}
		i = (i+1) % n;
	}
}

void printProcesses( int n)
{
	printf("PID\tArrival\tBurst\tFinish\tTAT\tWait\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",
			processes[i].pid,
			processes[i].arrival,
			processes[i].burst,
			processes[i].finish,
			processes[i].turnaround,
			processes[i].wait
		);
	}
}

void avgTWT( int n)
{
	float total = 0, avg;
	for(int i=0; i<n; i++)
	{
		total = total + (float) processes[i].turnaround;
	}
	avg = total/n;
	printf("Avg TWT: %.2f\n", avg);
}

void avgWT( int n)
{
	float total = 0, avg;
	for(int i=0; i<n; i++)
	{
		total = total + (float) processes[i].wait;
	}
	avg = total/n;
	printf("Avg WT: %.2f\n", avg);
}


void main()
{
	int n, q;
	printf("Enter n: ");
	scanf("%d", &n);
	
	printf("Enter q: ");
	scanf("%d", &q);

	for(int i=0; i<n; i++)
	{
		printf("Enter arrival time & burst time for process %d : ", i+1);
		processes[i].pid = i+1;
		scanf("%d %d", &processes[i].arrival, &processes[i].burst);
		processes[i].completed = 0;
		processes[i].remaining = processes[i].burst;
	}
	
	sortOnArrivalTime(n);
	
	calculateTimes(n, q);
	
	sortOnPID(n);
	
	printf("\nRound Robin Scheduling\n");
	printProcesses(n);
	avgTWT(n);
	avgWT(n);
}






