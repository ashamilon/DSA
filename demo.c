// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
void append();
void addatbegin();
void addatafter();
int length();
void display();
//oid deleteatbegin();
//void deleteatmid();
//void deleteatend();


struct node{
        int data;
        struct node* next;
};
int len;
struct node* head = NULL;//initially head value will be NULL. this is global variable
int main()
{
   struct node* temp,*ptr;
   int ch;
   while(1)
   {
       printf("\nSingle linked list operations\n");
       printf("1.Append\n");
       printf("2.Addatbegin\n");
       printf("3.Addatafter\n");
       printf("4.Length\n");
       printf("5.Display\n");
       printf("6.Deleteatbegin\n");
       printf("6.Deleteafter\n");
       printf("7.Deleteatend\n");
       printf("8.Quit\n");

       printf("Enter your choice:");
       scanf("%d",&ch);

       switch(ch)
       {
           case 1: append();
                   break;
           case 2: addatbegin();
                   break;
           case 3: addatafter();
                   break;
           case 4: len = length();
                   printf("Length is %d\n",len);
                   break;
           case 5: display();
                   break;
           /*case 6: deleteatbegin();
                   break;
           case 7: deleteatmid();
                   break;
           case 8: deleteatend();*/
                   break;
           case 9: exit(1);
                   break;
           default: printf("Invalid Input\n");
       }
   }
   
    return 0;
}
void append()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data:");
    scanf("%d",&temp->data);
    temp->next = NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else{
            struct node* p;
            p = head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next= temp;
    }
}
int length()
{
   int count = 0;
   struct node* temp;
   temp = head;
   while(temp!=NULL)
   {
      count++;
      temp=temp->next;
   }
   return count;
}
void display()
{
        struct node* temp;
        temp = head;
        if(temp==NULL)
        {
                printf("List is empty\n");
        }
        else{
          while(temp->next!=NULL)
          {
               temp = temp->next;
             printf("%d-->",temp->data);
            
          }
          printf("\n\n");
        } 
}
void addatbegin()
{
   struct node* temp;
   temp = (struct node*)malloc(sizeof(struct node));
   printf("Enter node data:");
   scanf("%d",&temp->data);
   temp->next= NULL;
   if(temp==NULL)
   {
           temp = head;
   }
   else{
           temp->next=head;
           head= temp;
   }
}
void addatafter()
{
  struct node* temp, *prv;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter node data:");
  scanf("%d",&temp->data);
  temp->next= NULL;
  int loc,i=1;
  printf("Enter location where to add:");
  scanf("%d",&loc);
  if(loc>len)
  {
    printf("Invalid Location\n");
  }
  else{
       prv = head;
       while(i<loc)
       {
             prv = prv->next;
             i++;  
       }
       temp->next=prv->next;
       prv->next=temp;
  }
}
/*void deleteatbegin()
{
    struct node* ptr;
    if(ptr==NULL)
    {
            printf("List empty\n");
    }
    else{
    head = ptr->next;
    free(ptr); 
    }   
}
void deletatmid()
{
   struct node* ptr, *prv;
   int pos;
   printf("Enter position to be delete:");
   scanf("%d",&pos);
   if(pos==1)
   {
       ptr=head;
        head = ptr->next;
        ptr->next=NULL;
        free(ptr);
   }
   else{
         ptr = prv = head;
         for(int i=0; i<pos; i++)
         {
              if(ptr==NULL)
              {
                      printf("Position not found\n");
              }
              else{
                      prv->next=ptr->next;
                      free(ptr);
              }   
         }
   }

}
void deleteatend()
{
    struct node* ptr, *prv;
   if(head==NULL)
   {
           printf("List already empty\n");
   }
   else{
           ptr = prv = head;
           while(ptr->next!=NULL)
           {
              prv = ptr;
              ptr = ptr->next;
           }
           prv->next=NULL;
           free(ptr);
   }
}*/