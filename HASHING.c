#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct node
{
  int data;
  struct node *next;
};
struct node *head[SIZE]={NULL},*ptr;
int divisionhash(int k)
{
  return k%SIZE;
}
void insert(int k)
{
  int i;
  struct node*new;
  i=divisionhash(k);
  new=(struct node *)malloc(sizeof(struct node));
  new->data=k;
  new->next=NULL;
  if(head[i]==NULL)
  {
    head[i]=new;
  }
  else
  {
    ptr=head[i];
    while(ptr->next != NULL)
    {
      ptr=ptr->next;
    }
    ptr->next=new;
  }

}
void display()
{
  int i;
  for(i=0;i<SIZE;i++)
  {
    ptr=head[i];
    while(ptr!=NULL)
    {
      if(ptr->next!=NULL)
      {
        printf("%d-->",ptr->data);
      }
      else
      {
        printf("%d",ptr->data);
      }
      ptr=ptr->next;
    }
    printf("\n");
  }
}
void search(int k)
{
  int i;
  i=divisionhash(k);
  if(head[i]==NULL)
  {
    printf("Search element not in list");
  }
  else
  {
    for(ptr=head[i];ptr!=NULL;ptr=ptr->next)
    {
      if(ptr->data==k)
      {
        printf("Search elament at index %d\n",i);
        break;
      }
    }
    if(ptr==NULL)
    {
      printf("Search element not in list");
    }
  }
}
int main()
{
  int choice,d,k;
  do
  {
    printf("\nOperations\n");
    printf("1.Insert\n");
    printf("2.Display\n");
    printf("3.Search\n");
    printf("4.Exit\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      {
        printf("\nEnter the number to be inseeted:");
        scanf("%d",&d);
        insert(d);
        break;
      }
      case 2:
      {
        display();
        break;
      }
      case 3:
      {
        printf("\nEnter the number to be Searched");
        scanf("%d",&k);
        search(k);
        break;
      }
      case 4:
      {
        printf("\nThank You\n");
        break;
      }
      default:
      {
        printf("Invalid choice:");
      }
    }
  } while(choice!=4);
}
