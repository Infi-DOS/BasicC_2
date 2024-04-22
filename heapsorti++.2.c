#include <stdio.h>

int N;
int pinakas[10];
int Hsize;
char c;

void print_array();
void built_heap();
void insert_heap();
void heapsort();
void heapify(int i);

int main ()
{
    printf("\nWelcome to proHeapSort");
    c='*';

    while(c!='q')
    {
        printf("\nPress i:to INSERT\tb:to BUILD Heap\ts:to HEAPSORT\tp:to PRINT and q:to QUIT\n");
        scanf("%c",&c);
        if(c=='i')
            insert_heap();
        if(c=='b')
            built_heap();
        if(c=='s')
            heapsort();
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
    for(j=0;j<10;j++)
    {
        printf("\nA[%d]=%d",j+1,pinakas[j]);
    }
}

void insert_heap()
{
    int i,k;
    printf("Vale 10 nea stoixeia ston pinaka\n");

    for(i=0;i<=9;i++)
    {
        scanf("%d",&k);
        pinakas[i]=k;
        printf("To neo stoixeio pou evales einai to:%d\n", pinakas[i]);
    }
    printf("Orizw ksana thn stathera Hsize=10 \n");
    Hsize=9;
}

void heapify(int i)
{
    int l,k,r,largest;
    r=2*i+1;
    l=2*i;
    printf("Gia i=%d Thetw duo statheres r=2*i+1=%d & l=2*i=%d pou aforoun ta antistoixa stoixeia tou pinaka\n",i,r+1,l+1);

    if((l<=Hsize)&&(pinakas[l]>pinakas[i]))
    {
        printf("To l=2*i=%d stoixeio einai megalutero apo to i=%d\n",l,i);
        largest=l;
    }
    else
    {
        printf("To l=2*i=%d stoixeio einai mikrotero apo to i=%d\n",l,i);
        largest=i;
    }

    if((r<=Hsize)&&(pinakas[r]>pinakas[largest]))
    {
        printf("To r=2*i+1=%d stoixeio einai megalutero apo to i=%d\n",r,i);
        largest=r;
    }

    if(largest!=i)
    {
        k=pinakas[i];
        pinakas[i]=pinakas[largest];
        pinakas[largest]=k;
        printf("Allagh tou stoixeiou i=%d me ton apo katw tou=%d\n",i,largest);
        heapify(largest);
    }
    else
        printf("Kai to 2*i+1=%d kai to 2*i=%d stoixeio einai mikrotero apo to i=%d\n",r,l,i);
}

void heapsort()
{
    int q,p;
    built_heap();

    for(q=9;q>=1;q--)
    {
        p=pinakas[0];
        pinakas[0]=pinakas[q];
        pinakas[q]=p;
        Hsize=Hsize-1;
        heapify(0);
    }
    printf("O pinakas taksinomithike\n");
    Hsize=9;
    print_array();
}

void built_heap()
{
    int m;
    for(m=4;m>=0;m--)
        heapify(m);
}
