#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node*left,*right;
}node;
int insert(node **t,int d)
{   node*ptr=(node*)malloc(sizeof(node));
    ptr->data=d;
    ptr->left=NULL;
    ptr->right=NULL;
    if(*t==NULL)
    *t=ptr;
    else
    {
        node *temp=*t;//,*p=NULL;
        while(temp->data!=d&&temp->right!=NULL)
            {
                //p=temp;
                temp=temp->right;
            }
        if(temp->right==NULL)
        temp->right=ptr;
        else
        {
            while(temp->left!=NULL)
            temp=temp->left;
            temp->left=ptr;
        }
    }

    return 0;
}
int inorder(node *tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	inorder(tree->left);
	printf("%d ",tree->data);
	inorder(tree->right);
	return 0;
}
int no_of_occur(node *t,int d)
{   int c=0;
    while((t->data!=d)&&(t!=NULL))
    t=t->right;
    if(t==NULL)
    return 0;
    while(t!=NULL)
        {   c++;
            t=t->left;
        }
    return c;
}
int main()
{   node*tree=NULL;
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++)
    {scanf("%d",&a[i]);
    insert(&tree,a[i]);
    }
    inorder(tree);
    int d;
    scanf("%d",&d);
    printf("%d", no_of_occur(tree,d));
    return 0;
}
