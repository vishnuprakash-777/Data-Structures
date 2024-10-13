#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
int visited_dfs[10];
int g[10][10],n;
void enqueue(int d)
{
  struct node *new;
  new=(struct node *)malloc(sizeof(struct node));
  new->data=d;
  new->next=NULL;
  if(front==NULL)
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
  d=temp->data;
  front=front->next;
  free(temp);
  return d;
}
int isempty()
{
  return front==NULL;
}
void bfs()
{
  int visited[10],i=0,node,j;
  for(j=0;j<n;j++)
  {
    visited[j]=0;
  }
  printf("%d ",i);
  visited[i]=1;
  enqueue(i);
  while(!isempty())
  {
    node=dequeue();
    for(j=0;j<n;j++)
    {
      if(g[node][j]==1 && visited[j]==0)
      {
        printf("%d ",j);
        visited[j]=1;
        enqueue(j);
      }
    }
  }
  printf("\n");
}
int dfs(int i)
{
  int j;
  printf("%d ",i);
  visited_dfs[i]=1;
  for(j=0;j<n;j++)
  {
    if(g[i][j]==1 && visited_dfs[j]==0)
    {
      dfs(j);
    }
  }
}
int main()
{
  int invalid=0,j,i;
  printf("Enter the number of nodes:");
  scanf("%d",&n);
  printf("Enter the adjacency matrix:");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&g[i][j]);
      if(g[i][j]!=0 && g[i][j]!=1)
      {
        invalid=1;
      }
    }
  }
  if(invalid==1)
  {
    printf("Enter the element 0 or1 \n");
  }
  printf("BFS traversal\n");
  bfs();
  printf("DFS traversal\n");
  dfs(4);
  printf("\n");
}
