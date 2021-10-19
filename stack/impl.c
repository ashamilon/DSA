#include <stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int stack[CAPACITY], top = -1;

int pop();
void push(int);
int isEmpty();
int isFull();
void peek();
void traverse();


void main()
{
    int n, item;
    while (1)
    {
        printf("\nchoose your option");
        printf("\n 1.PUSH\n 2.POP \n 3.PEEK \n 4.TRAVERSE \n 5.QUIT\n\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter an element");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            item=pop();
            if (item==0)
            {
                printf("stack overflowed");
            }
            else
                printf("%d is popped\n",item);
            break;
            
        case 3:
            peek();
            break;
        case 4:
            traverse();
            break;
        case 5:
            exit(0);
        default:
            printf("input invalid");
        }
    }
}
void push(int ele)
{
    if (isFull())
    {
        printf("stack overflowed");
    }
    else
    {
        top++;
        stack[top] = ele;
        printf("%d pushed to the stack",ele);
    }
}
int isFull()
{
    if(top==CAPACITY-1)
    {
        return 1;
    }
    else
    return 0;
}
int pop()
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        return stack[top--];
    }
    

}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
        return 0;
}

void peek()
{
    if (isEmpty())
    {
        printf("stack empty\n");
    }
    else
    {
        printf("Peek element is %d",stack[top]);
    }
    
}
void traverse()
{
    if (isEmpty())
    {
      printf("stack is Empty");
    }
    else
    {
        int i;
        printf("stack elements are: \n");
        for ( i = 0; i <=top; i++)
        {
            printf("%d\n",stack[i]);
        }
        
    }
    
}