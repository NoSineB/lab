#include<stdio.h>
int main()
{
    int reference[50],frame[50],fsize,i,j,flag=0,c=0,n,fault=0;
    float miss,hit;
    printf("Enter the n : ");
    scanf("%d",&n);
    printf("Enter the req : ");
    for(i=0;i<n;i++)
    scanf("%d",&reference[i]);
    printf("Enter the Frame size : ");
    scanf("%d",&fsize);
    for(i=0;i<fsize;i++)
    frame[i]=-1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<fsize;j++)
        {
            if(frame[j]==reference[i])
            flag=1;
        }
        if(flag !=1)
        {
            fault++;
            frame[c]=reference[i];
            c++;
        }
            if(c==fsize)
            c=0;
            flag=0;
      }
      printf("Total number of faults=%d\n",fault);
      miss=((float)fault/n)*100;
      hit=((float)(n-fault)/n)*100;
      printf("Toal number of hits=%d\n",n-fault);
      
      return 0;
 }
