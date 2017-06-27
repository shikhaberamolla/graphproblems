#include<stdio.h>
#include<stdlib.h>
void dijk(int[10][10],int s)
{
    int distance[10],u,v,minval,flag[10],count1=0,i,j,minpos;
    for(i=0;i<10;i++)
     {
         distance[i]=infinity;
         flag[i]=0;
     }
    distance[s]=0;
    flag[s]=1;
    u=s;
    while(count1<=9)
    {
         minval=99;
        for(j=0;j<10;j++)
        {
            if(distance[j]<minval && !flag[j])
               minval=distance[j],minpos=j;
        }
    for(i=0;i<10;i++)
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
   for(i=0;i<10;i++)
   {
       if(i!=s)
        printf("%d= %d\n",i,distance[i]);
   }
}

int main()
{
  int weight[10][10],i,j,source;
  printf("enter the weights\n");
  for(i=0;i<10;i++)
   {
       for(j=0;j<10;j++)
           scanf("%d",&weight[i][j]);
   }
  printf("enter source");
  scanf("%d",&source);
  dijk(weight,source);
  return 0;
}
