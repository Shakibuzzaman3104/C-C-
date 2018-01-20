#include <stdio.h>
#include <math.h>


void sieve(int n);

int nprime=1,prime[300000];
bool mark[100002];

void sieve(int n)
{
    int i,j;
    int limit=sqrt(n);
    mark[1]=1;
    for(i=4; i<=n; i+=2)
    {
        mark[i]=1;
    }

    prime[0]=2;

    for(i=3; i<=n; i+=2)
    {
        if(mark[i]!=1)
        {
            prime[nprime++]=i;
        }

        if(i<=limit)
        {
            for(j=i*i; j<=n; j+=i*2)
            {
                mark[j]=1;
            }
        }
    }

}

void print()

{
    int i;

    for(i=0; i<nprime; i++)
        printf("%d  ",prime[i]);

    nprime=1;
}

int main()
{

    int n,i;


    while(true)
    {
        printf("Please Enter The limit to find prime numbers:\n");
        scanf("%d",&n);
        sieve(n);
        print();
        printf("\n\n");
    }


    return 0;
}
