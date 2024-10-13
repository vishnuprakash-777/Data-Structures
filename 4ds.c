#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int d)
{
  struct node *new;
  new=(struct node *)malloc(sizeof(struct node));
  new->data=d;
  new->next=NULL;
  if(rear==NULL)
  {
    front=rear=new;
    rear->next=front;
  }
  else
  {
    rear->next=new;
    rear=new;
    rear->next=front;
  }
}
int dequeue()
{
  int d;
  struct node *temp;
  temp=front;
  if(rear==NULL)
  {
    printf("Circular Queue empty\n");
  }
  else if(rear==front)
  {
    front=rear=NULL;
    free(temp);
  }
  else
  {
    d=temp->data;
    front=front->next;
    rear->next=front;
    free(temp);
    return d;
  }
}
void display()
{
  struct node *temp;
  temp=front;
  if(rear == NULL)
  {
    printf("Circular Queue empty\n");
  }
  else
  {
    printf("THe queue is: ");
    do
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }while(temp!=front);
    printf("\n");
  }
}
