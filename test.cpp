#include<bits/stdc++.h>
using namespace std;
#define V 5
#define INF 99999
vector <vector<int> > route;
int parent[V][V];
int orien[V][V];
int dist[V][V];
int adj[V][V];
void create_graph();
struct nodes
{
    int lvi;
    int slvi;
};
struct sdis
{
    vector <vector<int> > sd;

};

struct nodes junc[V];
struct sdis sdist[V];
void printsolution(int dist[][V])
{
    int i,j;
printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }   
    
}

void printpath(int parent[][V],int u,int v,int index,int k1)
{
if(parent[u][v]==u)
{
    //printf("%d",u);
    sdist[k1].sd[index].push_back(u);
    return;
}
if(parent[u][v]!=INF)
{
//printf("%d<-",parent[u][v]);
sdist[k1].sd[index].push_back(parent[u][v]);
printpath(parent,u,parent[u][v],index,k1);
}
}

void floydwarshall(int graph[][V])
{
    int i,j,k;
    
    
    for(i=0;i<V;i++)
    for(j=0;j<V;j++)
    {
    dist[i][j]=graph[i][j];
    
    if(i==j)
    parent[i][j]=INF;
if(graph[i][j]!=INF)
parent[i][j]=i;
else
parent[i][j]=INF;
}
    
    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                dist[i][j]=dist[i][k]+dist[k][j];
                parent[i][j]=parent[k][j];
            }
            }
        }
    }
    printsolution(dist);
   // printf("\n\n");
    /*for(i=0;i<V;i++)
    for(j=0;j<V;j++)
    {
printf("Path between %d and %d passes through = \n",i,j);
if(parent[i][j]!=INF)
{
printf("%d<-",j);
    printpath(parent,i,j);
    printf("\n");
}
else
printf("No path\n");
}*/
}
void store(int index,int src,int des,int k1)
{
    if(parent[src][des]!=INF)
    {
        //printf("%d<-",des);
       sdist[k1].sd[index].push_back(des);
        printpath(parent,src,des,index,k1);
       // printf("\n");

    }
}
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 14, 12, INF, INF},
                       {14, 0, 11, 8, INF },
                       {12, 11, 0, 9, 2},
                       {INF, 8, 9, 0, 6},
                       {INF, INF, 2, 6,0}
                       
                      };
    


    
    floydwarshall(graph);
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
    {
     sdist[k].sd.push_back(vector<int>());
     store(i,k,i,k);
    }
    }

    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
    {
        int l=sdist[k].sd[i].size();
        reverse(sdist[k].sd[i].begin(),sdist[k].sd[i].end());
        for(int j=0;j<l;j++)
        {
            cout<<sdist[k].sd[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    
   }
