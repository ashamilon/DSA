#include <stdio.h>
#include <stdlib.h>
void append();
void addatafter();
void addatbegin();
int length();
void traverse();
struct node
{
    int data;
    struct node* right,*left;
};
typedef struct node node;
node* root;
int len;


void main()
{
    int choice;
    while (1)
    {
        printf("\n Double list Operations\n");
        printf("\n1.Append Node\n2.Insert at Begining\n3.Insert at any location\n4.Node Length\n5.Display \n6.exit");
        printf("\n Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: append();
                break;
        case 2: addatbegin();
                break;
        case 3: addatafter();
                break;
        case 4: len=length();
                break;
        case 5: traverse();
                break;
        case 6: exit(1);
        
        default:printf("invalid input\n");
                break;
        }
    }
}
void append()
{
    node* temp,*p;
    temp=(node*)malloc(sizeof(node));
    temp->right=NULL;
    temp->left=NULL;
    printf("\nEnter node data\n");
    scanf("%d",&temp->data);
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        p=root;
        while (p->right!=NULL)
        {
            p=p->right;
        }
        p->right=temp;
        temp->left=p;
        
    }
    
}
void addatbegin()
{
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->right=NULL;
    temp->left=NULL;
    printf("\nEnter the node data\n");
    scanf("%d",&temp->data);
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        root->left=temp;
        temp->right=root;
        root=temp;

    }
    
}
void addatafter()
{
    node* temp,*p=root;
    int loc,i=1;
    
    printf("\nEnter location to insert node data\n");
    scanf("%d",&loc);
    if (loc<len)
    {
        printf("\n invlaid location\n");
    }
    else
    {
        temp=(node*)malloc(sizeof(node));
        printf("\nEnter the node data\n");
        scanf("%d",&temp->data);
        temp->right=NULL;
        temp->left=NULL;

        while (i<loc)
          {
            p=p->right;
            i++;
        }
        temp->right=p->right;
        p->right->left=temp;
        temp->left=p;
        p->right-temp;

    }
    
    
    
}
int length()
{
    node* temp;
    temp=root;
    int count=0;
    while (temp!=NULL)
    {
        count++;
        temp=temp->right;
        
    }
    return count;
    
}
void traverse()
{
    node* temp=root;
    if (root==NULL)
    {
        printf("\nNode is empty\n");

    }
    else
    {
        while (temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->right;
        }
        
    }
    
}