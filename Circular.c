#include <stdio.h>
#include <stdlib.h>

struct slinklist
{
    int data;
    struct slinklist *next;
};

typedef struct slinklist node;

node* start=NULL;

node* getnode()
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}

void createlist(int n)
{
    node *newnode,*temp;
    for(int i=0;i<n;i++)
    {
       newnode=getnode();
       if(start==NULL)
       {
           start=newnode;
       }
       else
       {
           temp=start;
           while(temp->next!=NULL)
           {
               temp=temp->next;
           }
           temp->next=newnode;
       }
    }
    newnode->next=start;
}

void printlist(node* node)
{
    while(node->next!=start)
    {
        printf(" %d ",node->data);
        node=node->next;
    }
    printf(" %d \n",node->data);
}

int count(node* node)
{
    int n=1;
    while(node->next!=start)
    {
        n++;
        node=node->next;
    }
    return n;
}

node* insert(int pos)
{
    if(pos==1)
    {
        node* newnode=getnode();
        if(start==NULL)
        {
            start=newnode;
            newnode->next=start;
        }
        else
        {
            node *temp;
            temp=start;
            while(temp->next!=start)
            {
                 temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=start;
            start=newnode;
            temp->next=start;
        }
    }
    if(pos>1 && pos<=count(start))
    {
        node *newnode,*temp,*prev;
        int ctr=1;
        newnode=getnode();
        temp=prev=start;
        while(ctr<pos)
        {
            prev=temp;
            temp=temp->next;
            ctr++;
        }
        prev->next=newnode;
        newnode->next=temp;
    }
    if(pos==count(start)+1)
    {
       node *temp,*newnode=getnode();
            temp=start;
            while(temp->next!=start)
            {
                 temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=start;
    }
    return start;
}

node* delete(int pos)
{
    if(pos==1)
    {
        node *temp,*head;
        temp=head=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        start=start->next;
        temp->next=start;
        free(head);
    }
    if(pos>1 && pos<=count(start))
    {
        node *temp,*prev;
        int ctr=1;
        temp=start;
        while(ctr<pos)
        {
            prev=temp;
            temp=temp->next;
            ctr++;
        }
        prev->next=temp->next;
        free(temp);
    }
    if(pos==count(start)+1)
    {
        node *temp,*prev;
        temp=prev=start;
        while(temp->next!=start)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=start;
        free(temp);
    }
    return start;
}

void main()
{
    int n,pos;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    createlist(n);
    printf("The number of nodes in the linked list are: %d",count(start));
    printf("\nThe traversing of the linked list from left to right is: \n");
    printlist(start);  
    printf("Enter the position where you want to insert the element: ");
    scanf("%d",&pos);
    insert(pos);
    printlist(start);
    printf("Enter the position where you want to delete the element: ");
    scanf("%d",&pos);
    delete(pos);
    printlist(start);
}