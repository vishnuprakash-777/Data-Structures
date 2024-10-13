#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *header=NULL;
void insertatfront(int d)
{
  struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->next=header;
  header=new;
}
void insertatend(int d)
{
  struct node *new,*temp;
  temp=header;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->next=NULL;
  if(header==NULL)
  {
    header=new;
  }
  else
  {
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=new;
  }
}
void insertafter(int k,int d)
{
  struct node *new,*temp;
  temp=header;
  while(temp!=NULL)
  {
    if(temp->data==k)
    {
      new=(struct node*)malloc(sizeof(struct node));
      new->data=d;
      new->next=temp->next;
      temp->next=new;
      return;
    }
    temp=temp->next;
  }
  printf("The node %d does not exist\n",k);

}
void deletefromfront()
{
  struct node *temp,*pre;
  temp=header;
  if(temp==NULL)
  {
    printf("List empty\n");
    return;
  }
  header=temp->next;
  free(temp);
}
void deletefromend()
{
  struct node *temp,*pre;
  temp=header;
  if(temp==NULL)
  {
    printf("List empty\n");
    return;
  }
  else if(temp->next==NULL)
  {
    header=NULL;
    free(temp);
    return;
  }
  else
  {
    while(temp->next!=NULL)
    {
      pre=temp;
      temp=temp->next;
    }
    pre->next=NULL;
  }
}
void deleteafter(int k)
{
  struct node *temp,*prev;
  temp=header;
  if(temp==NULL)
  {
    printf("List empty\n");
    return;
  }
  else if(temp->data==k)
  {
    header=temp->next;
    free(temp);
    return;
  }
  while(temp!=NULL)
  {
    if(temp->data=k)
    {
      prev->next=temp->next;
      free(temp);
      return;
    }
    else
    {
      prev=temp;
      temp=temp->next;
    }
  }
  printf("The node %d does not exist\n",k);

}
void traverse()
{
  struct node *temp;
  temp=header;
  if(temp==NULL)
  {
    printf("List empty\n");
    return;
  }
  printf("The list is:\n");
  while(temp!=NULL)
  {
    printf("%d\t",temp->data);
    temp=temp->next;
  }
  printf("\n" );
}
int search(int k)
{
  int flag=0;
  struct node *temp;
  temp=header;
  while(temp!=NULL)
  {
    if(temp->data==k)
    {
      flag=1;
      break;
    }
    temp=temp->next;
  }
  return flag;

}
