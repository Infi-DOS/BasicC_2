
void print1(tp h)
{
    tp aux;
    aux=h;
    int i=1;
    while(aux!=NULL)
    {
        printf("Student:%d at Position in list:%d\n",aux->am,i);
        aux=aux->n;
        i++;
    }
}

void print2(tp h)
{
	if(h==NULL)
    {
        return;
    }
	if(h!=NULL)
	{
		printf("Student with am=%d\n",h->am);
		h=h->n;
		print2(h);
	}

}

void delstud(tp *h,tp *t)
{
	int AM;
	printf("Give the am that you want to delete\n");
	scanf("%d",&AM);
	getchar();
	if(((*h)!=NULL)&&((*h)->am==AM))
    {
        printf("This am was our header and does not exist at our list now\n");
        if((*h)->n==NULL)
        printf("The list now is empty\n");
        aux=*h;
		*h=(*h)->n;
		free(aux);
		return;
    }
    if((*h!=NULL)&&((*h)->am!=AM)&&((*h)->n==NULL))
    {
        printf("Our list has only one am and isnt that.\n ");
    }
    if((*h!=NULL)&&((*h)->am!=AM)&&((*h)->n!=NULL))
    {
        aux=*h;
        while((aux->n->am!=AM)&&(aux->n!=*t))
        {
            aux=aux->n;
        }
        if((aux->n->am!=AM)&&(aux->n==*t))
        {
            printf("This am does not exist at our list.\n");
            return;
        }
        tp aux2=aux->n;
        if(aux2==*t)
        {
            *t=aux;
        }
        aux->n=aux->n->n;
        free(aux2);
        printf("Fixed the tail and the am deleted.\n");
    }
}


