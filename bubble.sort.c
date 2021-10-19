#include<stdio.h>
#include<stdlib.h>
int temp;

void main()
{
    int n,*ptr;
    printf("\nEnter no of elements\n");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("\nEnter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",ptr+i);
    }
    printf("\n Elements are:");
    for (int i = 0; i < n; i++)
    {
        printf("%d-->",*(ptr+i));
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j<n-1-i; j++)
        {
            if (*(ptr+j)>*(ptr+j+1))
            {
                temp=*(ptr+j);
                *(ptr+j)=*(ptr+j+1);
                *(ptr+j+1)=temp;
            }
            
        }
        
    }

    printf("\nAfter Bubble sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d-->",*(ptr+i));
    }
    
    
    
    
	
}
