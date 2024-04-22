#include <stdio.h>
#include <stdlib.h>


typedef struct tf *tp;
struct tf
{
    char data;
    tp l,r;
};

tp p,s;

void insertdata(tp *p,tp *t);
void printenc(tp p);
void printdec(tp p);
void erasedata(tp *p,tp *t);

int main(void){

    printf("\nWelcome to ProgLIFO \n");
    char fry='a';
    p=NULL;
    s=NULL;


    while(fry!='q')
    {
        fry='a';
        printf("\nPress\ti:to INSERT DATA or e:to ERASE DATA and p:to PRINTENC or t:to PRINTDECR  all data from our progEncryption or q:QUIT\n",fry);
        fflush(stdin);
        fry=getchar();
        if(fry=='q')
            printf("QUIT\n");
        if(fry=='i')
        {
            printf("INSERT DATA\n");
            insertdata(&p);
        }
        if(fry=='e')
        {
            printf("ERASE DATA\n");
            if((p)==NULL)
            printf("The list is empty");
            if(p!=NULL)
            erasedata(&p,&b);
        }
        if(fry=='p')
        {
            printf("PRINTDEC\n");
            if(s==NULL)
            printf("The list is empty\n");
            if(s!=NULL)
            printenc(p);
        }
	    if(fry=='t')
	    {
	        printf("PRINTDEC\n");
	        if(p==NULL)
            printf("The list is empty\n");
            if(p!=NULL)
	        printdec(p);
	    }
    }
    return 0;
}

void insert(tp *p,tp *s)
{
    tp left,right,def;
    char xar;
    if(p==NULL)
    {
        printf("Give me the parent of your TT tree");
        xar=getchar();
    }
    if
    def=(tp)malloc(sizeof(struct tf));
    printf("Give me the parent\n");
    scanf("%d",&da);
    getchar();
    temp->am=da;
    temp->n=NULL;
    printf("Using temp=%d as the am you gave.\n",temp->am);
