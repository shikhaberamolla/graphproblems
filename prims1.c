#include<stdio.h>
#include<conio.h>
/* finding the minimum spanning tree    */
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},minv,mincost=0,cost[10][10];
int main()
{
printf("\n Enter the number of nodes:");
scanf("%d",&n);
printf("\n Enter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
visited[1]=1;
printf("\n");
 while(ne<n)
 {
  for(i=1,minv=999;i<=n;i++)
   for(j=1;j<=n;j++)
    if(cost[i][j]<minv)
     if(visited[i]!=0)
     {
      minv=cost[i][j];
      a=u=i;
      b=v=j;
     }
  if(visited[u]==0 || visited[v]==0)
  {
printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,minv);
mincost+=minv;
   visited[b]=1;
  }
  cost[a][b]=cost[b][a]=999;
 }
printf("\n Minimun cost=%d",mincost);
return(0);
}
