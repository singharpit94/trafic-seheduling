#include<bits/stdc++.h>
using namespace std;
#define V 9
#define INF 99999
vector <vector<int> > route;
int parent[V][V];
int orien[V][V];
int dist[V][V];
struct nodes
{
	int lvi;
	int slvi;
};

struct nodes junc[V];
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

void printpath(int parent[][V],int u,int v,int index)
{
if(parent[u][v]==u)
{
    //printf("%d",u);
    route[index].push_back(u);
    return;
}
if(parent[u][v]!=INF)
{
//printf("%d<-",parent[u][v]);
route[index].push_back(parent[u][v]);
printpath(parent,u,parent[u][v],index);
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
    printf("\n\n");
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
void store(int index,int src,int des)
{
    if(parent[src][des]!=INF)
    {
        //printf("%d<-",des);
       route[index].push_back(des);
        printpath(parent,src,des,index);
        printf("\n");

    }
}
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 14, INF, INF, INF, INF, INF, 12, INF},
                       {14, 0, 8, INF, INF, INF, INF, 11, INF},
                       {INF, 8, 0, 7, INF, 4, INF, INF, 2},
                       {INF, INF, 7, 0, 9, 14, INF, INF, INF},
                       {INF, INF, INF, 9, 0, INF, INF, INF, INF},
                       {INF, INF, 4, INF, INF, 0, 2, INF, INF},
                       {INF, INF, INF, 14, INF, 2, 0, 2, 6},
                       {12, 11, INF, INF, INF, INF, 2, 0, 9},
                       {INF, INF, 2, INF, INF, INF, 6, 9, 0}
                      };
 
    int t,s1=0,d1=0;
    int s[50];
    int d[50];
    int max_seg_size=0;

    memset(orien,INF,sizeof(orien));
    for(int i=0;i<9;i++)
    {
    	junc[i].lvi=0;
    	junc[i].slvi=0;
    }
    //  for(int i=0;i<9;i++)
    // {
    // 	cout<<junc[i].lvi<<endl;
    // 	cout<<junc[i].slvi<<endl;
    // }
    for(int i=0;i<9;i++)
    {
    	for(int j=0;j<9;j++)
    	{
    		if(graph[i][j]!=INF)
    			orien[i][j]=1;
    		else
    			orien[i][j]=2;
    	}
    }
    // for(int i=0;i<9;i++)
    // {
    // 	for(int j=0;j<9;j++)
    // 	{
    // 		cout<<orien[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }
    cout<<endl;
    cout<<endl;
     for(int i=0;i<9;i++)
    {
    	for(int j=0;j<9;j++)
    	{
    		if(j>i && orien[i][j]!=2)
    		{
    			orien[i][j]=1;
    			orien[j][i]=0;
    		}
    	}
    	
    }
    //  for(int i=0;i<9;i++)
    // {
    // 	for(int j=0;j<9;j++)
    // 	{
    // 		cout<<orien[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }
    memset(junc,0,sizeof(junc));

    cout<<"Enter the number of source and destination\n";
    cin>>t;
    while(t--)
    {
        cout<<"Enter the source for the  route\n";
        cin>>s[s1];
        s1++;
        cout<<"Enter the destination for the  route\n";
        cin>>d[d1];
        d1++;

 
    }
    floydwarshall(graph);
   // cout<<s1<<endl;
    for(int i=0;i<s1;i++)
    {   route.push_back(vector<int>());
        store(i,s[i],d[i]);
    }
    
    for(int i=0;i<s1;i++)
    {
        int l=route[i].size();
        if(l>max_seg_size){
        	max_seg_size=l;
        }
        reverse(route[i].begin(),route[i].end());

         for(int j=0;j<l;j++)
            cout<<route[i][j]<<" ";
        cout<<"\n";
    }
    cout<<max_seg_size<<endl;
    for(int i=1;i<max_seg_size;i++)
    {
    	for(int j=0;j<s1;j++)
    	{    
            // cout<<route[j].size()<<endl;
    		if(i<route[j].size())
    		{
    		 	cout<<route[j][i-1]<<" "<<route[j][i]<<endl;
    		 	
    		 		int k2=junc[route[j][i]].slvi;

                    int k1=junc[route[j][i-1]].slvi;
                    cout<<k1<<" "<<k2<<endl;
                    if(k1==0 && k2==0 )
                   {
                    junc[route[j][i]].lvi=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                   }

                    else if(k1==k2)
                    {



                        cout<<route[j][i]<<" "<<route[j][i-1]<<endl;
                        if(route[j][i]>route[j][i-1])
                        {
                            cout<<dist[route[j][i-1]][route[j][i]]<<endl;
                            junc[route[j][i]].lvi=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                            cout<<junc[route[j][i]].lvi<<endl;
                        }
                        else
                        {
                            junc[route[j][i]].lvi=2*dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                        }
                    }
                    else if(k1<k2)
                    {
                              junc[route[j][i]].lvi=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                    }
                    else if(k1>k2)
                    {
                        int z1=junc[route[j][i]].slvi;
                        int z2=dist[route[j][i-1]][route[j][i]];
                        int z3=junc[route[j][i-1]].slvi;
                        if((z1+z2)<z3)
                        {
                            junc[route[j][i]].lvi=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                        }
                        else
                        {
                            junc[route[j][i]].lvi=2*z2+z1;
                        }
                    }


    		 		

    		

    	}
    }
    for(int j=0;j<9;j++)
    {   

        cout<<junc[j].lvi<<endl;
        junc[j].slvi=junc[j].lvi;
    }
    
    }
    
    
    return 0;
}