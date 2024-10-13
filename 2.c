#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
  new->data=d;
  new->next=top;
  top=new;
}
int pop()
{
  int d;
  struct node *temp;
  temp=top;
  d=temp->data;
  top=top->next;
  free(temp);
  return d;
}
int main()
{
  char e, postfix[100];
  int i=0,a,b,r;
  printf("Enter the postfix expression:");
  fgets(postfix,100,stdin);
  printf("%d\n",strlen(postfix));
  for(i=0;i<strlen(postfix)-1;i++)
  {
    e=postfix[i];
    if(isdigit(e))
    {
      /*printf("%d\n",e);
      printf("%d\n",'0');
      printf("%d\n",e-'0');*/
      push(e-'0');
    }
    else
    {
      a=pop();
      b=pop();
      switch(e)
      {
        case '+':
          r=a+b;
          break;
        case '-':
          r=a-b;
          break;
        case '*':
          r=a*b;
          break;
        case '/':
          r=a/b;
          break;
        case '^':
          r=pow(a,b);
          break;
      }
      push(r);
    }

  }
  printf("\nThe result=%d\n",r);
}
