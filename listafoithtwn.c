#include<stdio.h>
#include<stdlib.h>

typedef struct tf *tp;
    struct tf
    {   int am;
        double gr;
        tp n;};

tp h,t,temp,aux;

void insert(tp *h,tp *t);
void print1(tp h);
void print2(tp h);
void delstud(tp *h,tp *t);

int main(void){
    char fry,fry2;
    fry='a';
    h=NULL;
    t=NULL;
    printf("\nWelcome to pro_list \n");
    while(fry!='q')
    {
        fry='a';
        printf("\nPress\ti:insert or d:delete a student and p:print1 or t:print2  all students from our list or q:quit\n",fry);
        fflush(stdin);
        fry=getchar();
        getchar();
        if(fry=='q')
            printf("QUIT\n");
        if(fry=='i')
        {
            printf("INSERT\n");
            insert(&h,&t);
        }
        if(fry=='d')
        {
            printf("DELETE\n");
            delstud(&h,&t);
        }
        if(fry=='p')
        {
            printf("print_1\n");
            print1(h);
        }
	    if(fry=='t')
	    {
	        printf("print_2\n");
	        print2(h);
	    }
    }
    return 0;
}

void insert(tp *h,tp *t)
{
    tp temp,aux;
    int da;
    temp=(tp)malloc(sizeof(struct tf));
    printf("Give me the AM integer\n");
    scanf("%d",&da);
    getchar();
    temp->am=da;
    temp->n=NULL;
    printf("The AM of temp is %d\n",temp->am);

    if((*h!=NULL) && (temp->am < (*h)->am))
    {
        printf("The am you inserted is the lowest of our list\n");
        temp->n=*h;
        *h=temp;
        printf("The am now is at first position of our list\n");
    }
    if((*h!=NULL) && ((*h)->n!=NULL) && (temp->am > (*h)->am))
    {
        int i=2;
        aux=*h;
        printf("The am>am_h, higher from our first lower am\nchecking next\n");

        while((aux->n!=NULL) && (aux->n->am < temp->am))
        {
            i++;
            printf("Our inserted am>from next\n");
            aux=aux->n;
        }

        if(aux->n!=NULL)
        {
            if(aux->am == temp->am)
            {
                printf("This am already exists");
            }
            printf("%d os sth seira\n",i);
            printf("inserting at next\n");
            temp->n=aux->n;
            aux->n=temp;
        }
        if(aux->n==NULL)
        {
            printf("We found the highest am at our list and that you inserted is higher");
            temp->n=aux->n;
            aux->n=temp;
            *t=temp;
        }
    }
    if((*h!=NULL) && ((*h)->n==NULL) && (temp->am > (*h)->am))
    {   printf("That was the second am at our list and the last one\n");
        (*h)->n=temp;
        *t=temp;
    }
    if((*h)==NULL)
    {   printf("The HEAD is NULL, the list was empty we insert the first\n");
        *h=temp;
        *t=temp;
        printf("First %d\n",temp->am);
    }
}

void print1(tp h)
{
    tp aux;
    aux=h;
    while(aux!=NULL)
    {
        printf("Current is %d\n",aux->am);
        aux=aux->n;
    }
}

void print2(tp h)
{
	if(h==NULL)
        {return;}
	if(h!=NULL)
	{
		printf("Student # %d\n",h->am);
		h=h->n;
		print2(h);
	}

}

void delstud(tp *h,tp *t){
	int AM;
	printf("Dose AM gia diagrafh\n");
	scanf("%d",&AM);
	getchar();
	if(*h==NULL){printf("H lista einai kenh\n");}
	if(*h!=NULL)
    {
		if((*h!=NULL)&&(AM==(*h)->am)){
		aux=*h;
		*h=(*h)->n;
		free(aux);
    }
    if((*h!=NULL)&&(AM!=(*h)->am)&&((*h)->n!=NULL))
    {
        aux=*h;
        while((aux->n->am!=AM)&&(aux->n!=*t))
        {
            aux=aux->n;
        }
        if(aux->n==*t)
        {
            printf("Den uparxei h kataxorhsh\n");
            return;
        }
        tp aux2=aux->n;
        if(aux2==*t)
        {
            *t=aux;
        }
        aux->n=aux->n->n;
        free(aux2);
		}
		if((*h!=NULL)&&(AM!=(*h)->am)&&((*h)->n==NULL))
        {
            printf("Den uparxei h kataxorhsh\n");
        }
	}
}

