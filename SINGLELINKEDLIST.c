#include<stdio.h>
#include "5ds.c"
int main()
{
  int choice;
  do
  {
    int d,k;
    printf("Linked list operations:");
    printf("\n1.Insert at fornt\n2.Insert at end\n3.Insert after\n4.Delete at fornt\n5.Delete at end\n5.Delete after\n7.Traverse\n8.Search\n9.Exit\n\n");
    printf("Enter the choice:");
    scanf("%d",&choice );
    switch(choice)
    {
      case 1:
      printf("Enter the element to be inserted at front" );
      scanf("%d",&d);
      insertatfront(d);
      break;
      case 2:
      printf("Enter the element to be inserted at end" );
      scanf("%d",&d);
      insertatend(d);
      break;
      case 3:
      printf("Enter the element to be inserted" );
      scanf("%d",&d);
      printf("Element after to be inseeted");
      scanf("%d",&k);
      insertafter(k,d);
      break;
      case 4:
      deletefromfront();
      break;
      case 5:
      deletefromend();
      break;
      case 6:
      printf("Enter the element after to be deleted:");
      scanf("%d",&k);
      deleteafter(k);
      break;
      case 7:
      traverse();
      break;
      case 8:
      printf("Enter the elemnt to be Searched");
      scanf("%d",&k);
      if(search(k)==1)
      {
        printf("Element found in the list\n");
      }
      else
      {
        printf("Element not found in the list\n");
      }
      break;
      case 9:
      printf("Thank you\n");
      break;
      default:
      printf("Invalid Choice\n");


    }
  }while(choice!=9);
}
