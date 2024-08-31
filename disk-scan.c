#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,n,rq[100],h,index,size,dir,temp,sum=0;
    printf("Enter head : ");
    scanf("%d",&h);
    printf("Enter n : ");
    scanf("%d",&n);
    printf("Enter reqs :\n");
    
    for(i=0;i<n;i++)
    scanf("%d",&rq[i]);
    

    printf("Enter ds : ");
    scanf("%d",&size);
    
    printf("1 for right 0 for left : ");
    scanf("%d",&dir);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(rq[j]>rq[j+1])
            {
                temp = rq[j];
                rq[j] = rq[j+1];
                rq[j+1] = temp;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(h<rq[i])
        {
            index = i;
            break;
                    }
    }
    
    if(dir == 1)
    {
        for(i=index;i<n;i++)
        {
            sum = sum + abs(rq[i] - h);
            h = rq[i];
        }
        
        sum = sum + abs(size-1-h);
        h = size-1;
        
        for(i=index-1;i>=0;i--)
        {
            sum = sum + abs(rq[i] - h);
            h = rq[i];
        }
    }
    else
    {
        for(i=index;i>=0;i--)
        {
            sum = sum + abs(rq[i] - h);
            h = rq[i];
        }
        
        sum = sum + abs(0 - h);
        h = 0;
        
        for(i=index+1;i<n;i++)
        {
            sum = sum + abs(rq[i] - h);
            h = rq[i];
        }
    }
       printf("\nHEAD   = %d \n",sum);
}
