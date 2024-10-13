#include<stdio.h>
#include<stdlib.h>
int main()
{
  int i,j,temp,*a,c=0,n;
  printf("Enter the number of elements");
  scanf("%d",&n);
  a=(int *)malloc(n*sizeof(int));
  printf("Enter the elements to be sorted:");
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  for(i=0;i<=n-2;i++)
  {
    for(j=0;j<=n-i-2;j++)
    {
      c++;
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
  printf("Number of comparisons done = %d\n",c);
  printf("The sorted order is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",*(a+i));
  }
  printf("\n");
}
