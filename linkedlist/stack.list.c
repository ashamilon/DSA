#include<stdio.h>
#include<stdlib.h>
void traverse();
void push();
void pop();

struct node
{
    int data;
    struct node* link;
};
typedef struct node stack;
stack* top=NULL;
void main()
{
    int choice;
    while (1)
    {
        printf("single link lsit using stack\n");
        printf("\n1.push element \n2.pop\n3.Traverse\n 4.exit\n");
        printf("Enter any choice: \t");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: traverse();
                 break;
        case 4: exit(1);
        
        default: printf("invalid input\n");
            break;
        }
    }
    
}
void push()
{
    stack* temp;
    temp=(stack*)malloc(sizeof(stack));
    printf("\nenter a node element\n");
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;

}
void pop()
{
    stack* temp;
    if (top==NULL)
    {
        printf("\n no elements in stack\n");
    }
    else
    {
        temp=top;
        printf("\n Top element is %d",temp->data);
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
    
}
void traverse()
{
    stack* temp;
    if (top==NULL)
    {
        printf("\n No elements in stack\n");
    }
    
    temp=top;
    while (temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->link;

    }
    
}
