#include<stdio.h>

typedef struct{
	int pid;
	int arrival;
	int burst;
	int start;
	int finish;
	int turnaround;
	int wait;
} Process;

Process processes[20];

void sortOnArrivalTime(int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(processes[j].arrival > processes[j+1].arrival)
			{
				Process temp = processes[j];
				processes[j] = processes[j+1];
				processes[j+1] = temp;
			}
		}
		
	}
}

void sortOnPID(int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(processes[j].pid > processes[j+1].pid)
			{
				Process temp = processes[j];
				processes[j] = processes[j+1];
				processes[j+1] = temp;
			}
		}
		
	}
}

void calculateTimes(int n)
{
	int currentTime = 0;
	
	for(int i = 0; i<n; i++)
	{
		if(currentTime < processes[i].arrival)
		{
			currentTime = processes[i].arrival;
		}
		
		processes[i].start = currentTime;
		processes[i].finish = currentTime + processes[i].burst;
		processes[i].wait = processes[i].start - processes[i].arrival;
		processes[i].turnaround = processes[i].finish - processes[i].arrival;
		
		currentTime = processes[i].finish;
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
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		printf("Enter arrival time & burst time for process %d : ", i+1);
		processes[i].pid = i+1;
		scanf("%d %d", &processes[i].arrival, &processes[i].burst);
	}
	
	sortOnArrivalTime(n);
	
	calculateTimes(n);
	
	sortOnPID(n);
	
	printf("\nFCFS Scheduling\n");
	printProcesses(n);
	avgTWT(n);
	avgWT(n);
}






