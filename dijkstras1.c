#include<stdio.h>
#include<conio.h>
#define infinity 99
/*function that finds shortest path from source to all the node
    input is the weight matrix and source node*/
void dijk(int[5][5],int s)
{
    int distance[5],u,v,minval,flag[5],count1=0,i,j,minpos;
    for(i=0;i<5;i++)
     {
         distance[i]=infinity;
         flag[i]=0;
     }
    distance[s]=0;
    flag[s]=1;
    u=s;
    while(count1<=4)
    {
         minval=99;
        for(j=0;j<5;j++)
        {
            if(distance[j]<minval && !flag[j])
               minval=distance[j],minpos=j;
        }
    for(i=0;i<5;i++)
    {
        if(weight[u][i]!=0 && !flag[i])
            {
                if(distance[u]+weight[u][i]<distance[i])
                    distance[i]=distance[u]+weight[u][i];
                if(distance[i]<minval)
                  {
                   minval=distance[i];
                   minpos=i;
                  }
            }
    }
    flag[minpos]=1;
    count1++;
    u=minpos;
   }
   printf("the shortest distances from source %d to: \n",s);
   for(i=0;i<5;i++)
   {
       if(i!=s)
        printf("%d= %d\n",i,distance[i]);
   }
}
/*  main function    */
int main()
{
  int weight[5][5],i,j,source;
  printf("enter the weights\n");
  for(i=0;i<5;i++)      //entering the weight matrix
   {
       for(j=0;j<5;j++)
           scanf("%d",&weight[i][j]);
   }
  printf("enter source");
  scanf("%d",&source);
  dijk(weight,source);      //function call
  return 0;
}
