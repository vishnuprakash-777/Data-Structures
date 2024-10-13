#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *top=NULL;
void push(int d)
{
  struct node *new;
  new=(struct node *)malloc(sizeof(struct node));
  if(new==NULL)
  {
    printf("Stack Overflow");
    exit(1);
  }
  new->data=d;
  new->next=top;
  top=new;
}
int pop()
{
  int d;
  struct node *temp;
  //temp=(struct node *)malloc(sizeof(struct node));
  temp=top;
  if(top==NULL)
  {
    return NULL;
  }
  else
  {
    d=temp->data;
    top=top->next;
    free(temp);
    return d;
  }
}
void display()
{
  struct node *temp;
  temp=top;
  if(top==NULL)
  {
    printf("The Stack is empty\n");
  }
  else
  {
    printf("The stack is:");
    while(temp!=NULL)
    {
      printf("%d\n",temp->data);
      temp=temp->next;
    }
  }
}
