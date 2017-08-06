#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
};
 
struct Node *addToEmpty(struct Node *last, int data)
{
    // This function is only for empty list
    if (last != NULL)
      return last;
 
    // Creating a node dynamically.
    struct Node *temp = 
           (struct Node*)malloc(sizeof(struct Node));
 
    // Assigning the data.
    temp -> data = data;
    last = temp;
 
    // Creating the link.
    last -> next = last;
 
    return last;
}
 
struct Node *addBegin(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    struct Node *temp = 
            (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
 
    return last;
}
 
struct Node *addEnd(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
     
    struct Node *temp = 
        (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
 
    return last;
}
 
struct Node *addAfter(struct Node *last, int data, int item)
{
    if (last == NULL)
        return NULL;
 
    struct Node *temp, *p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;
 
            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);
 
    cout << item << " not present in the list." << endl;
    return last;
 
}
 
void traverse(struct Node *last)
{
    struct Node *p;
 
    // If list is empty, return.
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    // Pointing to first Node of the list.
    p = last -> next;
 
    // Traversing the list.
    do
    {
        cout << p -> data << " "<<'\n';
        p = p -> next;
 
    }
    while(p != last->next);
 
}
 
// Driven Program
int main()
{
    struct Node *last = NULL;
 	int ch,c,y=1;
	do
	{	cin>>ch;
		switch(ch)
	{case 1:cin>>c;
    		last = addToEmpty(last, c);
			break;
     case 2:cin>>c;
		    last = addBegin(last, c);
			break;
	 case 3:cin>>c;
			last = addEnd(last, c);
    		break;
		
     case 4:traverse(last);
			break;
	 default:cout<<"fuck";
			break;
	}
	cout<<"0/1\n";
	cin>>y;
	}while(y);
   // last = addAfter(last, 10, 8);
 
    
 
    return 0;
}
