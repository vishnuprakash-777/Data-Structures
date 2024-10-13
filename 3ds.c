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
  if(front==NULL && rear==NULL)
  {
    front=rear=new;
  }
  else
  {
    rear->next=new;
    rear=new;
  }
}
int dequeue()
{
  struct node *temp;
  int d;
  temp=front;
  if(front==NULL)
  {
    printf("Queue empty\n");
  }
  d=temp->data;
  front=front->next;
  free(temp);
  return d;
}
void display()
{
  struct node *temp;
  temp=front;
  if(front==NULL)
  {
    printf("Queue empty\n");
  }
  else
  {
    printf("\nThe queue is");
    while(temp!=NULL)
    {
      printf("%d\n",temp->data);
      temp=temp->next;
    }
  }
}
