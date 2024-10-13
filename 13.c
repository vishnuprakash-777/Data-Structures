#include<stdio.h>
#include<stdlib.h>
void mergesort(int *a,int lb,int ub);
void merge(int *a,int lb,int mid,int ub);
int c=0,n;
int main()
{
  int i,j,temp,*a;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  a=(int *)malloc(n*sizeof(int));
  printf("Enter the elements to be sorted:");
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  mergesort(a,0,n-1);
  printf("Number of comparisons done = %d\n",c);
  printf("The sorted order is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",*(a+i));
  }
  printf("\n");
}
void mergesort(int *a,int lb,int ub)
{
  int mid;
  if(lb<ub)
  {
    mid=(lb+ub)/2;
    mergesort(a,lb,mid);
    mergesort(a,mid+1,ub);
    merge(a,lb,mid,ub);
  }
}
void merge(int *a,int lb,int mid,int ub)
{
  int i,j,k,*b;
  b=(int *)malloc(n*sizeof(int));
  i=lb;
  j=mid+1;
  k=lb;
  while(i<=mid && j<=ub)
  {
    c++;
    if(a[i]<=a[j])
    {
      b[k]=a[i];
      i++;
    }
    else
    {
      b[k]=a[j];
      j++;
    }
    k++;
  }
  while(i<=mid)
  {
    b[k]=a[i];
    k++;
    i++;
  }
  while(j<=ub)
  {
    b[k]=a[j];
    k++;
    j++;
  }
  for(k=lb;k<=ub;k++)
  {
    a[k]=b[k];
  }
}
