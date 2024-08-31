#include<stdio.h>
#include<stdlib.h>

void main()
{
	int h, n, req[50], totalSeek=0;
	printf("Enter head: ");
	scanf("%d", &h);
	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter req: ");
	for(int i=0; i<n; i++)
	{
		scanf("%d", &req[i]);
	}
	for(int i=0; i<n; i++)
	{
		totalSeek += abs(h - req[i]);
		h = req[i];
	}
	printf("Total head movement = %d\n", totalSeek);
}
