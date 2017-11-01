#include<stdio.h>
#include<stdlib.h>
struct node
{	int data;
	struct node*next;
};
int insertbefore(struct node*h,int d,int c)
{	struct node*l=NULL,*p=h;
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	while((p!=NULL))
	{l=p;
		  p=p->next;
		if(p->data==d)
		{temp->data=c;
		 l->next=temp;
		 temp->next=p;
		 break;
		}
	}
	return 0;
}
int push(struct node**h,int d)
{	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=d;
	ptr->next=*h;
	*h=ptr;
	return 0;
}
int show(struct node*n)
{	while(n!=NULL)
	{printf("%d\n",n->data);
 		n=n->next;
	}
	return 0;

}
int atlast(struct node**h,int d)
{	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=d;
	ptr->next=NULL;
	if(*h==NULL)
	{*h=ptr;}
	else 
	{struct node*l=*h;
	while(l->next!=NULL)
	l=l->next;
	l->next=ptr;}
	return 0;
}
int insertafter(struct node*t,int c,int d)
{	while(t!=NULL&&t->data!=c)
	t=t->next;
	if(t!=NULL)
	{struct node*p=(struct node*)malloc(sizeof(struct node));
		struct node*temp=t->next;
		t->next=p;
		p->data=d;
		p->next=temp;
	}
	return 0;
}

int fun(struct node*h)
{
	if(h==NULL)
	return 0;
	if(h->next!=NULL) 
	fun(h->next->next);
	printf("%d",h->data);
	return 0;
}
int delete(struct node**h,int d)
{	struct node*temp=*h;
	struct node*prev=NULL;
	if((temp!=NULL)&&(temp->data==d))
	{*h=temp->next;
		free(temp);
	}
	while((temp!=NULL)&&(temp->data!=d))
	{prev=temp;
		temp=temp->next;
	}
	  if (temp == NULL) 
 	exit(0);
	 prev->next = temp->next;
 
    free(temp);  // Free memory
	return 0;
}
int deleteatkey(struct node**h,int key)
{	struct node*temp=*h,*prev=NULL;
	int i=1;
	if(temp==NULL)
	return 0;
	if(key==1&&temp!=NULL)
	{
		*h=temp->next;
		 free(temp);
	}
	else 
	{while(temp!=NULL&&i!=key)
	{prev=temp;
	 temp=temp->next;
	 i++;
	}
	if(temp!=NULL)
	{prev->next=temp->next;
	free(temp);
	}
	}
	return 0;
}
int rearrange(struct node*h)
{	while(h!=NULL&&h->next!=NULL)
	{int t=h->data;
	 h->data=h->next->data;
	 h->next->data=t;
	 h=h->next->next;
	}
	return 0;
}
int oddeven(struct node**h)
{	struct node*odd=NULL,*even=NULL;
	int i=0;
	while(*h!=NULL)
	{if(i%2==0)
		push(&even,(*h)->data);
	 else push(&odd,(*h)->data);
	 i++;
	 (*h)=(*h)->next;
	}
	*h=even;
	struct node*l=even;
	while(l->next!=NULL)
	l=l->next;
	l->next=odd;
	while(even!=NULL)
	{printf("%d ",even->data);
	 even=even->next;
	}
	return 0;
}
int length(struct node*head)
{	if(head==NULL)
	return 0;
	return length(head->next)+1;
}
int main()
{	struct node*head=NULL;
	int i,ch,n,c,d;
	int y=1;
	//scanf("%d",&n);
	do
	{scanf("%d",&ch);
		switch(ch)
		{case 1:scanf("%d",&c);
				push(&head,c);
				break;
		 case 2:scanf("%d",&c);
				atlast(&head,c);
				break;
		 case 3:scanf("%d",&c);
				delete(&head,c);
				break;
		 case 4:scanf("%d%d",&c,&d);
				insertafter(head,c,d);
				break;
		 case 5:show(head);
				break;
		 case 6:scanf("%d",&c);
				deleteatkey(&head,c);
				break;
		 case 7:scanf("%d",&c);
				scanf("%d",&d);
				insertbefore(head,d,c);
				break;
		 case 8:fun(head);
				break;
		 case 9:rearrange(head);
				break;
		 case 10:oddeven(&head);
				 break;
		 case 11:printf("%d\n",length(head));
				 break;
		 default:printf("fuck\n");
				 break;
		}
	printf("0/1\n");
	scanf("%d",&y);
	
	}while(y);
	return 0;
}
