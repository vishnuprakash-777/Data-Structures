#include<stdio.h>
#include"1ds.c"
int main()
{
  int choice,d;
  do
  {
    printf("\nStack Operations\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      {
        printf("\nEnter the number to be pushed:");
        scanf("%d",&d);
        push(d);
        break;
      }
      case 2:
      {
        d=pop();
        if(d!=NULL)
        {
          printf("The popped item is %d\n",d);
        }
        else
        {
          printf("The stack is empty\n");
        }
        break;
      }
      case 3:
      {
        display();
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
