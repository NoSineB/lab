#include<stdio.h>

typedef struct{
	int pid;
	int arrival;
	int burst;
	int priority;
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

int findNextProcess(int n, int currentTime)
{
	int highestPriority = -1;
	for(int i=0; i<n; i++)
	{
		if(!processes[i].completed && processes[i].arrival <= currentTime)
		{
			if(highestPriority == -1 || processes[i].priority < processes[highestPriority].priority)
			{
				highestPriority = i;
			}
		}
	}
	
	return highestPriority;
}

void calculateTimes(int n)
{
	int currentTime = 0;
	int completedProcesses = 0;
	
	while(completedProcesses < n)
	{
		int nextProcess = findNextProcess(n, currentTime);
		
		if(nextProcess == -1)
		{
			currentTime++;
			continue;
		}
		
		
		processes[nextProcess].start = currentTime;
		processes[nextProcess].finish = currentTime + processes[nextProcess].burst;
		processes[nextProcess].wait = processes[nextProcess].start - processes[nextProcess].arrival;
		processes[nextProcess].turnaround = processes[nextProcess].finish - processes[nextProcess].arrival;
		
		
		currentTime = processes[nextProcess].finish;
		processes[nextProcess].completed = 1;
		completedProcesses++;
	}
}

void printProcesses( int n)
{
	printf("PID\tArrival\tBurst\tPrior\tFinish\tTAT\tWait\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
			processes[i].pid,
			processes[i].arrival,
			processes[i].burst,
			processes[i].priority,
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
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		printf("Enter arrival time, burst time, & priority for process %d : ", i+1);
		processes[i].pid = i+1;
		scanf("%d %d %d", &processes[i].arrival, &processes[i].burst, &processes[i].priority);
		processes[i].completed = 0;
	}
	
	sortOnArrivalTime(n);
	
	calculateTimes(n);
	
	sortOnPID(n);
	
	printf("\nPriority Scheduling\n");
	printProcesses(n);
	avgTWT(n);
	avgWT(n);
}






