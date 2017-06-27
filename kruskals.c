#include<stdio.h>
/*  structure that defines an edge  */
struct edge{ int src,dst,weight;
               };
int belong[20];
int findset(int n)
{
    return(belong[n]);
}
/*  union set   */
void unionv(int a,int b,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(belong[i]==b)
            belong[i]=a;
    }
}
/*  function to sort the edges in order to selct the one with minimum weight    */
void sortedges(struct edge graph[],int n)
{
    int i,j;
    struct edge tmp;
    for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if((graph[i].weight)>(graph[j].weight))
          {
               tmp=graph[i];
               graph[i]=graph[j];
               graph[j]=tmp;
          }
       }
   }
}
/*  function to find edge with minimum weight
        input is an array of edges          */
void kruskals(struct edge graph[],int n)
{
    int minweight=0,i,v1,v2;
    for(i=0;i<n;i++)
    {   v1=findset(graph[i].src);
        v2=findset(graph[i].dst);
        if(v1!=v2)
        {
            //printf("weight included %d\n",graph[i].weight);
            minweight=minweight+graph[i].weight;
            unionv(v1,v2,n);

        }

    }
    printf("\n the minimum weight is %d\n",minweight);
}
/*  main function   */
int main()
{
    struct edge graph[20];
    int n,i;
    printf("enter the total number of edges\n");
    scanf("%d",&n);
    printf("enter the nodes and weight of the edges\n");
    for(i=0;i<n;i++)
    {   belong[i]=i;
        scanf("%d%d%d",&graph[i].src,&graph[i].dst,&graph[i].weight);
    }
    sortedges(graph,n);
    kruskals(graph,n);
    return 0;
}
