#include <stdlib.h>
#include <stdio.h>

int N=32;
int Hsize;
char c;
int pinakas[32];
int pinakas1[32/2],pinakas2[32/2];

void print_array();
void insert_array(int n);
void mergesort();
void merge();

int main ()
{
    printf("\nWelcome to proMergeSort");
    c='*';

    while(c!='q')
    {
        printf("\nPress i:to INSERT\tm:to MERGE\ts:to MERGESORT\tp:to PRINT and q:to QUIT\n");
        scanf("%c",&c);
        if(c=='i')
            insert_array(N);
        if(c=='m')
            merge();
        if(c=='s')
            mergesort();
        if(c=='p')
            print_array();
        getchar();
    }
    return 0;
}

void print_array()
{
    int j;
    printf("O pinakas apoteleitai apo:\n");
    for(j=0;j<N/2;j++)
    {
        printf("\nA[%d]=%d",j+1,pinakas[j]);
    }
    for(j=0;j<N/2;j++)
    {
        printf("\nA[%d]=%d",j+1,pinakas2[j]);
    }
}

void insert_array(int n)
{
    int i,k;
    printf("\nVale %d nea stoixeia ston pinaka\n",n);

    for(i=0;i<=n-1;i++)
    {
        printf("A[%d]=",i+1);
        scanf("%d",&k);
        pinakas[i]=k;
        if(i<=n)
        pinakas1[i]=k;
        else
        pinakas2[i-16]=k;
    }
}

void merge()
{
    int m,f,l,p,q,w,i;
    f=0;
    p=f;
    l=15;
    q=l;
    m=f+(f+1-l)/2;
    w=0;
    while((p!=m)&&(q!=l))
    {
        if(pinakas[p]<pinakas[q])
        {

            pinakas2[w]=pinakas[p];
            w++;
            p++;
        }
        else
        {
            pinakas2[w]=pinakas[q];
            w++;
            q--;
        }
    }
    if(p==m)
    {
        for(i=q;i<l+1;i++)
        {
            pinakas2[i+m];
        }
        while(q!=l+1)
        {
            pinakas2[w]=pinakas[q];
        w++;
        q--;
        }
    }
    else
    {
        while(p!=m)
        {
            pinakas2[w]=pinakas[p];
        w++;
        p++;
        }
    }
}

void mergesort()
{

}
