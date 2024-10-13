#include<stdio.h>
#include"3ds.c"
int main()
{
  int choice,d;
  do
  {
    printf("\nQueue Operations\n");
    printf("1.enqueue\n");
    printf("2.dequeue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      {
        printf("\nEnter the number to be enqueued:");
        scanf("%d",&d);
        enqueue(d);
        break;
      }
      case 2:
      {
        d=dequeue();
        printf("The dequeued element is %d\n",d);
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
