#include <stdio.h>

int N=10;
int Hsize;
char c;
int pinakas[N];
//Se periptwsh pou theloume na valoume diko mas megethos ston pinaka xrhsimopoioume to N kai pointers
void print_tree();
void print_array();
void built_heap();
void insert_heap(int n);
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
        {
            insert_heap(N);
        }
        if(c=='b')
            built_heap();
        if(c=='s')
            heapsort();
        if(c=='p')
        {
            print_array();

        }

        getchar();
    }
    return 0;
}

void print_array()
{
    int j;
    printf("O pinakas apoteleitai apo:\n");
    for(j=0;j<N;j++)
    {
        printf("\nA[%d]=%d",j+1,pinakas[j]);
    }
}
void print_tree()
{
    int j=0;
    printf("\n\t\t\t\tHEAP\n=====================================================================\n");
    printf("\t\t\t\tA[%d]\n",j+1);
    printf("\t\tA[%d]\t\t\t\tA[%d]\n",j+2,j+3);
    printf("\tA[%d]\t\tA[%d]\t\tA[%d]\t\tA[%d]\n",j+4,j+5,j+6,j+7);
    printf("A[%d]\t\tA[%d]\tA[%d]\n\n",j+8,j+9,j+10);
}

void insert_heap(int n)
{
    int i,k;
    printf("\nVale %d nea stoixeia ston pinaka\n",n);

    for(i=0;i<=n-1;i++)
    {
        printf("A[%d]=",i+1);
        scanf("%d",&k);
        pinakas[i]=k;
    }
    printf("\nOrizw thn stathera Hsize=%d\n",n);
    Hsize=n;
}

void heapify(int i)
{
    int l,k,r,largest;


    i++;
    printf("~Elegxos sto %do stoixeio\n",i);
    r=2*i+1;
    l=2*i;
    printf("Thetw duo statheres r=2*i+1=%d l=2*i=%d afou to i=%d \n",r,l,i);

    if(l>N)
    {
        printf("!!!!ERROR!!!! To A[%d] kai A[%d] den anhkoyn ston pinaka\n",r,l);
        return;
    }
    if(l==N)
        printf("!!!!ERROR!!!! To A[%d] den anhkei ston pinaka\n",r);

    if((l<=Hsize)&&(pinakas[l-1]>pinakas[i-1]))
    {
        printf("To A[%d]=%d > A[%d]=%d\n",l,pinakas[l-1],i,pinakas[i-1]);
        largest=l;
    }
    else
    {
        printf("To A[%d]=%d <= A[%d]=%d\n",l,pinakas[l-1],i,pinakas[i-1]);
        largest=i;
    }

    if((r<=Hsize)&&(pinakas[r-1]>pinakas[largest-1]))
    {
        printf("To A[%d]=%d > A[%d]=%d\n",r,pinakas[r-1],i,pinakas[i-1]);
        largest=r;
    }


    if(largest!=i)
    {

        k=pinakas[i-1];
        pinakas[i-1]=pinakas[largest-1];
        pinakas[largest-1]=k;
        printf("Allagh tou stoixeiou i=%d me ton apo katw tou=%d\n",i,largest);
        heapify(largest-1);
    }
    else
        printf("To A[%d]=%d <= A[%d]=%d\n",r,pinakas[r-1],i,pinakas[i-1]);
}

void heapsort()
{


    int q,p;

    built_heap();

    printf("\n~~~~~HEAPSORTING~~~~~\n");

    for(q=N-1;q>=1;q--)
    {
        printf("~~~~Change A[0]=%d with A[%d]=%d\n",pinakas[0],q+1,pinakas[q]);
        p=pinakas[0];
        pinakas[0]=pinakas[q];
        pinakas[q]=p;
        Hsize=Hsize-1;
        printf("~~~~Setting HSIZE-1=%d\n",Hsize);
        printf("~~~~Now calling heapify(0);\n");

        heapify(0);
    }
    printf("O pinakas taksinomithike\n");
    Hsize=N;
    print_array();
}

void built_heap()
{
    printf("\n~~~~~BUILDING HEAP~~~~~\n");
    int m;
    for(m=N/2;m>=0;--m)
        heapify(m);
    print_array();
    print_tree();
}
