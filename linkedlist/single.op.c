#include<stdio.h>
#include<stdlib.h>
void append();
int length();
void display();
void delete();
void insertatafter();
void insertatbegin();
void swap();
void reverse_list();
struct node
{
    int data;
    struct node* link;
    
    
};
struct node* root;
int len;
void main()
{
    int choice;
    while (1)
    {
        printf("\n Enter Your choice\n");
        printf("\n1.Append\n2.Insert at begin\n3.Insert at specified\n4.Node Length\n5.Display\n6.Delete\n7.swap\n8.reverse the elements\n 9.Quit\n");

        printf("\nenter any option\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: append();
                break;
        case 2: insertatbegin();
                break;
        case 3: insertatafter();
                break;
        case 4: len=length();
                printf("length of the list is %d",len);
                break;
        case 5: display();
                break;
        case 6: delete();
                break;
        case 7: swap();
                break;
        case 8: reverse_list();
                break;
        case 9: exit(1) ;
        
        default:
            printf("invalid input\n");
            break;
        }
    }
    
}

void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter node data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else{
        struct node* p;
        p=root;
        while (p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
        
    }


}
int length()
{
    struct node* temp;
    temp=root;
    int count=0;
    
    if (temp==NULL)
    {
        printf("\nNode Empty\n");
    }
    else
    {
        while (temp!=NULL)
        {
            count++;
            temp=temp->link;
        }
        return count;
        
    }
    
}
void display()
{
    struct node* temp;
    temp=root;

    if (temp==NULL)
    {
        printf("\nNode Empty\n");
    }
    else
    {
        while (temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
    }
}
void insertatafter()
{
    struct node* temp, *p;
    int loc,i=1;
    printf("Enter location to add\n");
    scanf("%d",&loc);
    if (loc>len)
    {
        printf("invalid location\n");
        printf("current node sixe is %d",len);
    }
    else
    {
        p=root;
        while (i<loc)
        {
            p=p->link;
            i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter node data\n");
        scanf("%d",&temp->data);

        temp->link=NULL;
        temp->link=p->link;
        p->link=temp;

        
    }
    
    
}
void insertatbegin()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the node to insert\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
    

}
void delete()
{
    struct node* temp;
    int  loc;
    printf("Enter location you wanna delete\n");
    scanf("%d",&loc);
    if (loc>length())
    {
        printf("\n No such location\n");
    }
    else if (loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        struct node* p=root,*q;
        int i=1;
        while (i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
        
    }
    
    
}
void reverse_list()
{
    int i,j,k;
    struct node* temp,*p,*q;
    i=0;
    j=len-1;
    while (i<j)
    {
        k=0;
        while (k<j)
        {
            q=q->link;
            k++;
        }
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        i++;
        j--;
        p=p->link;
        q=root;
        
    }
    
}
void swap()
{
    int i=1,j=1,k=1,l=1,loc1,loc2;
    printf("enter two location to swap\n");
    scanf("%d %d",&loc1,&loc2);
    struct node* temp,*p,*q,*r,*s;
    p=root;
    q=root;
    r=root;
    s=root;

    if (loc1>length() || loc2>length())
    {
        printf("\n not enough elements to swap\n");
    }
    if (length()<2)
    {
        printf("not enought elements\n");
    }
    /*if((loc1-loc2)<2)
    {
        if(loc1<loc2)
        {
            while (i<loc1)
        {
            p=p->link;
            i++;
        }
        while (j<loc1+1)
         {
            r=r->link;
            j++;
        }
        while (j<loc1+2)
        {
            r=r->link;
            j++;
        }

        }
        else
        {
               while (i<loc1)
        {
            p=p->link;
            i++;
        }
        while (j<loc1-1)
         {
            r=r->link;
            j++;
        }
        while (j<loc1-2)
        {
            r=r->link;
            j++;
        }
        }
            r->link=q->link;
            r->link=q;
            p->link=r;

    }
    
    else
    {*/
            while (i<loc1-1)
    {
        p=p->link;
        i++;
    }
    while (j<loc1)
    {
        r=r->link;
        j++;
    }
    while (k<loc2-1)
    {
        s=s->link;
        k++;
    }
    while (l<loc2)
    {
        q=q->link;
        l++;
    }
    p->link=q;
    r->link=q->link;
    s->link=r;
    q->link=s;
    //}
    
    
    


}
