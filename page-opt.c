#include<stdio.h>
int main()
{
    int i,j,k,l,m,n,p,c=0,s;
    int a[20],b[20],q,max;
    printf("Enter n : ");
    scanf("%d",&n);
    printf("Enter size of frame : ");
    scanf("%d",&m);
    printf("Enter reqs : \n");
    
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(j=0; j<m; j++)
        b[j]=-1; 
    for(i=0; i<n; i++)
    {
        for(k=0; k<m; k++)
            if(b[k]==a[i])
                goto here;
        for(j=0; j<m; j++)
        {
            if(b[j]==-1)
            {
                b[j]=a[i];
                c++;
                goto here;
            }
        }
        if(j==m)
        {
            l=i+1,max=0;
                for(j=0; j<m; j++)
            {
                for(s=l; s<n; s++)
                {
                    if(a[s]==b[j])
                    {
                        if(s>max)
                        {
                            max=s;
                            p=j;
                        }
                        break;
                    }
                }
                if(s==n)
                {
                    max=s;
                    p=j;
                }
            }
        }
        b[p]=a[i];
        c++;
 here:
       printf("\t");
    }
    printf("No.of page fault is: %d \n",c);
      printf("No.of page hit is: %d \n",(n-c));
    
}
