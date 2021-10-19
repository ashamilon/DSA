#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

int queue[CAPACITY];
int front=0,rear=0;

void insert(int);
void traverse();
void delete();


void main()
{
    int choice;
    while (1)
    {
        int ele;
        printf("\nQueue operations\n");
        printf("\n1.Insert Element\n2.Delete element\n3.Display element\n4.QUit\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: printf("\n Enter element to add\n");
                scanf("%d",&ele);
                insert(ele);
                break;
        case 2: delete();
                break;
        case 3: traverse();
                break;
        case 4: exit(1);
        
        default:
         printf("\n invalid input\n");
          break;
        }
    }
    
}
void insert(int ele)
{
    if (CAPACITY==rear)
    {
        printf("\nQ is Empty\n");
    }
    else 
    {
        queue[rear]=ele;
        rear++;
    }
    
}
void delete()
{
    if (front==rear)
    {
        printf("\nQ is empty");
    }
    else
    {
        printf("%d deleted",queue[front]);
        for (int i=0; i<rear;i++)
        {
            queue[i]=queue[i+1];
        }
        
    }
    
}
void traverse()
{
    if (front==rear)
    {
        printf("\nQ is empty");
    }
    else
    {
        printf("\n Queue elements are:");
        for (int i = 0; i < rear; i++)
        {
            printf("%d\n",queue[i]);
        }
        
    }
}