#include<bits/stdc++.h>
using namespace std;
#define V 30
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
    int pdep;
    int dep;
    int tres;
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
   
   int graph[V][V];
    

    int t,s1=0,d1=0;
    int s[50];
    int d[50];
    int max_seg_size=0;

    memset(orien,INF,sizeof(orien));
    memset(adj,INF,sizeof(orien));
    for(int i=0;i<V;i++)
    {
    	junc[i].lvi=0;
    	junc[i].slvi=0;
        junc[i].pdep=0;
        junc[i].dep=0;
        junc[i].tres=3;
    }
    //  for(int i=0;i<9;i++)
    // {
    // 	cout<<junc[i].lvi<<endl;
    // 	cout<<junc[i].slvi<<endl;
    // }
    for(int i=0;i<V;i++)
    {
    	for(int j=0;j<V;j++)
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
     for(int i=0;i<V;i++)
    {
    	for(int j=0;j<V;j++)
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
     int din;
     int max_time=0;
     int edgesg=0;
     freopen("adj1.txt", "r", stdin);
     for(int i=0;i<V;i++)
     {
        for(int j=0;j<V;j++)
            {cin>>din;
        if(din==999)
            graph[i][j]=INF;
        else
            {graph[i][j]=din;
                if(din!=0)
                    edgesg++;
            }
     }

     }
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
            int flag=0;
            int flag1=0;
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

                    else 
                    {

                       //loop should be checked
                        for(int g1=0;g1<s1;g1++)
                        {
                            if(route[g1][i]==route[j][i-1])
                            {
                                flag=1;
                                break;
                            }
                        }

                          if(flag==1)
                          {
                              cout<<route[j][i-1]<<" "<<route[j][i]<<endl;

                                    for(int h1=0;h1<s1;h1++)
                                    {
                                        if(route[h1][i-1]==route[j][i] && route[h1][i-2]==route[j][i-1] )
                                        {
                                            flag1=1;
                                            break;
                                        }
                                    }

                                   if(flag1==1)
                                   {
                                        int z1=junc[route[j][i-2]].slvi+dist[route[j][i-2]][route[j][i-1]];
                                        int z2=junc[route[j][i-2]].slvi+(dist[route[j][i-2]][route[j][i-1]]/2);
                                        if(z1<z2 && junc[route[j][i-1]].tres<3)
                                        { 
                                              int yo=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                                            if(yo>junc[route[j][i]].lvi)
                                              junc[route[j][i]].lvi=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                                              junc[route[j][i-1]].tres++;
                                              if(junc[route[j][i-1]].tres>3)
                                                junc[route[j][i-1]].tres=0;
                                            int yo1=2*dist[route[j][i-1]][route[j][i]]+junc[route[j][i]].slvi;
                                            if(yo1>junc[route[j][i]].slvi)
                                                junc[route[j][i]].lvi=yo1;


                                        }
                                        else
                                        {
                                             int yo=2*dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                                            if(yo>junc[route[j][i]].lvi)
                                              junc[route[j][i]].lvi=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                                              junc[route[j][i-1]].tres++;
                                              if(junc[route[j][i-1]].tres>3)
                                                junc[route[j][i-1]].tres=0;         
                                        }
                                   }
                                   else
                                   {
                                        if(k1<k2 )
                                        {
                                             int yo=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                                            if(yo>junc[route[j][i]].lvi)
                                              junc[route[j][i]].lvi=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                                              junc[route[j][i-1]].tres++;
                                              if(junc[route[j][i-1]].tres>3)
                                                junc[route[j][i-1]].tres=0;
                                         }
                                         else
                                         {
                                             int yo=2*dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                                            if(yo>junc[route[j][i]].lvi)
                                              junc[route[j][i]].lvi=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                                              junc[route[j][i-1]].tres++;
                                              if(junc[route[j][i-1]].tres>3)
                                                junc[route[j][i-1]].tres=0;
                                         }

                                        }
                                       
                               
                          }
                          else
                          {

                             int yo=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                            if(yo>junc[route[j][i]].lvi)
                              junc[route[j][i]].lvi=dist[route[j][i-1]][route[j][i]]+junc[route[j][i-1]].slvi;
                             junc[route[j][i-1]].tres++;
                             if(junc[route[j][i-1]].tres>3)
                                junc[route[j][i-1]].tres=0;
                          }
                        
                    }
                   
                    

    		 		

    		

    	}
    }

    cout<<"Nodes Values after  "<<i<<"  iterations\n";
    for(int j=0;j<V;j++)
    {   
        
        cout<<"Node "<<j<<" ---   "<<junc[j].lvi<<endl;
        junc[j].slvi=junc[j].lvi;
    }
    
    }
    
    
   
    return 0;
}

void create_graph()
{
    int i,max_edges,origin,destin,w,n;

    printf("Enter number of vertices : ");
    scanf("%d",&n);
    max_edges = n*(n-1);

    for(i=1;i<=max_edges;i++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ",i);

        scanf("%d %d",&origin,&destin);
        printf("Enter distance\n");
        scanf("%d",&w);

        if((origin == -1) && (destin == -1))
            break;
        if( origin >= n || destin >= n || origin<0 || destin<0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
        {
            adj[origin][destin] = w;
            adj[destin][origin]=w;
        }
    }/*End of for*/
}/*End of create_graph()*/
