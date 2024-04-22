#include<stdio.h>
#include<stdlib.h>

typedef struct tf *tp;
    struct tf
    {   int data;
        tp n;
    };

tp s,b;

void pushdata(tp *s,tp *b);
void print1(tp s);
void print2(tp s);
void popdata(tp *s,tp *b);

char fry;

int main(void){
    fry='a';
    s=NULL;
    b=NULL;
    printf("\nWelcome to ProgLIFO \n");
    while(fry!='q')
    {
        fry='a';
        printf("\nPress\tu:to PUSH or o:to POP data and p:to PRINT1 or t:to PRINT2  all data from our LIFO list or q:QUIT\n",fry);
        fflush(stdin);
        fry=getchar();
        getchar();
        if(fry=='q')
            printf("QUIT\n");
        if(fry=='u')
        {
            printf("PUSH\n");
            pushdata(&s,&b);
        }
        if(fry=='o')
        {
            printf("POP\n");
            if((s)==NULL)
            printf("The list is empty");
            if(s!=NULL)
            popdata(&s,&b);
        }
        if(fry=='p')
        {
            printf("PRINT_1\n");
            if(s==NULL)
            printf("The list is empty\n");
            if(s!=NULL)
            print1(s);
        }
	    if(fry=='t')
	    {
	        printf("PRINT_2\n");
	        if(s==NULL)
            printf("The list is empty\n");
            if(s!=NULL)
	        print2(s);
	    }
    }
    return 0;
}

void pushdata(tp *s,tp *b)
{
    tp temp,aux;
    int datain;
    temp=(tp)malloc(sizeof(struct tf));
    printf("Give me the data to insert it\n");
    scanf("%d",&datain);
    getchar();
    temp->data=datain;
    temp->n=NULL;
    printf("Using temp=%d as the data you inserted.\n",temp->data);

    if((*s!=NULL))
    {   temp->n=*s;
        *s=temp;
        printf("Setting stack\n");
    }

    if(((*s)==NULL))
    {
        printf("The Stack is NULL, the ProgLIFO was empty and we PUSH first data\n");
        *s=temp;
        *b=temp;
        printf("First %d\n",temp->data);
    }

}

void print1(tp s){
    tp aux;
    aux=s;
    printf("Stack DATA is %d.",aux->data);
    if(aux->n==NULL)
        printf("\t<-The Bottom");
    printf("\n");
    while(aux->n!=NULL)
    {
        aux=aux->n;
        printf("This  DATA is %d.",aux->data);
        if(aux->n==NULL)
            printf("\t<-The Bottom");
        printf("\n");
    }


}

void print2(tp s){
	if(s==NULL)
	return;
	if(s!=NULL)
	{
		printf("Data # %d\n",s->data);
		s=s->n;
		print2(s);
	}

}

void popdata(tp *s,tp *b)
{
    tp aux=*s;
	if((*s)->n==NULL)
    {
        printf("The list has only one data and will POP\n");
        *s=(*s)->n;
		free(aux);
		printf("The progLIFO now is empty\n");
		return;
    }
    if((*s)->n!=NULL)
    {
        printf("Stack will move one position\n");
		*s=(*s)->n;
		free(aux);
    }
}


