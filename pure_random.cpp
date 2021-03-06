#include<bits/stdc++.h>
using namespace std;
#define V 5
#define INF 99999
#define MAX 100  
int parent[V][V];
int orien[V][V];
int dist[V][V];
struct places
{
	int lvi;
	int slvi;
};

struct places junc[V];

struct des{
		vector <vector<int> > route;
	};

struct distances
{
  struct des dis[V];
	
};
struct sdis
{
    vector <vector<int> > sd;

};

struct distances nodes[V];
struct sdis sdist[V];
int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/
int disi[MAX][MAX];
void create_graph();
void printAllPathsUtil(int z,int u, int d, bool visited[],
                              int path[], int &path_index);
void printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
 
    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty
 
    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s,s, d, visited, path, path_index);
}

void printAllPathsUtil(int z,int u, int d, bool visited[],
                              int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
    	nodes[z].dis[d].route.push_back(vector<int>());
    	int l=nodes[z].dis[d].route.size();

        for (int i = 0; i<path_index; i++)
            {
            	//cout << path[i] << " ";
            	nodes[z].dis[d].route[l-1].push_back(path[i]);


        }
            // cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        // list<int>::iterator i;
        // for (i = adj[u].begin(); i != adj[u].end(); ++i)
        //     if (!visited[*i])
        //         printAllPathsUtil(*i, d, visited, path, path_index);

        for(int i=0;i<V;i++)
        {
        	if(adj[u][i] == 1 && visited[i]==false)
        		 printAllPathsUtil(z,i, d, visited, path, path_index);
        }
    }
 
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
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
   // printsolution(dist);
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
    srand (time(NULL));
	int max_seg=0;
	int t,s1=0,d1=0,k1,k2,p1,p2,now,flag,i=1;
    int s[50];
    int d[50];
    int curr[50];
    for(int i=0;i<V;i++)
    {
    	junc[i].lvi=0;
    	junc[i].slvi=0;
    }
    //create_graph();
   //  adj[0][1] = 1;
   //  adj[1][0] = 1;
   // adj[0][2]=1;
   // adj[2][0]=1;
   // adj[1][2]=1;
   // adj[2][1]=1;
   // adj[1][3]=1;
   // adj[3][1]=1;
   // adj[2][4]=1;
   // adj[4][2]=1;
   // adj[2][3]=1;
   // adj[3][2]=1;
   // adj[3][4]=1;
   // adj[4][3]=1;
   //  disi[0][1] = 14;
   //  disi[1][0] = 14;
   // disi[0][2]=12;
   // disi[2][0]=12;
   // disi[1][2]=11;
   // disi[2][1]=11;
   // disi[1][3]=8;
   // disi[3][1]=8;
   // disi[2][4]=2;
   // disi[4][2]=2;
   // disi[2][3]=9;
   // disi[3][2]=9;
   // disi[3][4]=6;
   // disi[4][3]=6;
    
   //  int graph[V][V] = {{0, 14, 12, INF, INF},
   //                     {14, 0, 11, 8, INF },
   //                     {12, 11, 0, 9, 2},
   //                     {INF, 8, 9, 0, 6},
   //                     {INF, INF, 2, 6,0}
                       
   //                    };
    int graph [V][V];
    int din;
   int max_time=0;
   int edgesg=0;
   ofstream myfile;
     freopen("random.txt", "r", stdin);
     for(int i=0;i<V;i++)
     {
      for(int j=0;j<V;j++)
      {
        cin>>din;
        adj[i][j]=din;
        if(din!=0)
          edgesg++;
      }
     }

    for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
      {
        cin>>din;
        if(din==999)
        {
          graph[i][j]=INF;
          disi[i][j]=0;

        }
        else
        {
          graph[i][j]=din;
          disi[i][j]=din;
        }
      }
    }

     
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
    for(int i=0;i<V;i++){

    	for(int j=0;j<V;j++)
    {
    	printAllPaths(i,j);
    }
    }
    
    cout<<endl;

    //int l=nodes[0].route.size();
   // cout<<l<<endl;
    for(int y=0;y<V;y++)
    {
    	for(int i=0;i<V;i++){
    	int l=nodes[y].dis[i].route.size();
        for(int j=0;j<l;j++)
        {
        	int k=nodes[y].dis[i].route[j].size();
        	if(k>max_seg)
        		max_seg=k;
        	for(int z=0;z<k;z++)
        		{
        			//cout<<nodes[y].dis[i].route[j][z]<<" ";
        		}
        	   //cout<<endl;
        }
     }
    } 

     cout<<"Max Segment  "<<max_seg<<endl;
    i=1;
    flag=1;
    while(flag){
       
    	for(int j=0;j<s1;j++)
    	{
              if(i==1)
              {
                     now=s[j];
                     cout<<"Current Location for "<<j<<"  route "<<now<<endl;
                     cout<<"Destination Location for "<<j<<"  route "<<d[j]<<endl;
                   

              }
              else
              {
                            now=curr[j];
                            cout<<"Current Location for "<<j<<"  route "<<now<<endl;
                            cout<<"Destination Location for "<<j<<"  route"<<d[j]<<endl;
              }
                    if(now!=d[j])
                    {

                              
                                {
                                        int len=nodes[now].dis[d[j]].route.size();
                                        int isSecret=rand() % len;
                                       //cout<<isSecret<<endl;
                                        int len1=nodes[now].dis[d[j]].route[isSecret].size();
                                        cout<<"Route Selected for "<<j<<" route"<<endl;
                                        for(int z=0;z<len1;z++)
                                        {
                                          cout<<nodes[now].dis[d[j]].route[isSecret][z]<<" ";
                                        }
                                        cout<<endl;
                                        k1=junc[now].slvi;
                                        k2=junc[nodes[now].dis[d[j]].route[isSecret][1]].slvi;
                                        p1=now;
                                        p2=nodes[now].dis[d[j]].route[isSecret][1];
                                        if(k1==0 && k2==0)
                    {
                      junc[p2].lvi=disi[p1][p2]+k1;
                    }
                    else if(k1==k2)
                    {
                              if(p2>p1)
                              {
                                int yo=disi[p1][p2]+k1;
                                if(yo>junc[p2].lvi)
                                junc[p2].lvi=disi[p1][p2]+k1;
                              }
                              else
                              {
                                 int yo=2*disi[p1][p2]+k1;
                                if(yo>junc[p2].lvi)
                                junc[p2].lvi=2*disi[p1][p2]+k1;
                              }
                    }
                    else if(k1<k2)
                    {
                       int yo=disi[p1][p2]+k1;
                      if(yo>junc[p2].lvi)
                      junc[p2].lvi=disi[p1][p2]+k1;
                    }
                    else if(k1>k2)
                    {
                               if((k2+disi[p1][p2])<k1)
                               {
                                
                                  int yo=disi[p1][p2]+k1;
                                if(yo>junc[p2].lvi)
                                junc[p2].lvi=disi[p1][p2]+k1;
                               }
                               else
                               {

                                 int yo=2*disi[p1][p2]+k1;
                                if(yo>junc[p2].lvi)
                                junc[p2].lvi=2*disi[p1][p2]+k1;
                               }
                    }

                      curr[j]=p2;


                                }





                                
                    
                    //cout<<k1<<" "<<k2<<endl;
                    //cout<<p1<<" "<<p2<<endl;
                    
              
    	}

      else
      {

      }
                    }
               
               cout<<"Nodes Values after  "<<i<<"  iterations\n";
    	for(int j=0;j<V;j++)
    {   

       
        cout<<"Node "<<j<<" ---  "<<junc[j].lvi<<endl;
        junc[j].slvi=junc[j].lvi;
        if(junc[j].slvi>max_time)
          max_time=junc[j].slvi;
    }
    flag=0;
    i++;

     for(int u=0;u<s1;u++)
     {
      if(curr[u]!=d[u])
      {
        flag=1;
        break;
      }
     }

    }
     int longest_path =0;
    for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
      {
           if(dist[i][j]!=INF && dist[i][j]>longest_path)
            longest_path=dist[i][j];
      }
    }
     myfile.open("output_random.txt");
    for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
      {
        myfile<<graph[i][j]<<" ";
      }
      myfile<<"\n";
    }
   
    myfile<<"Longest path= "<<longest_path<<"\n";
    myfile<<"MAX TIme= "<<max_time<<"\n";
     myfile<<"vertices= "<<V<<"\n";
    myfile<<"edges= "<<edgesg/2<<"\n";

    
   
    
	return 0;
}
void create_graph()
{
	int i,max_edges,origin,destin,w;

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
			adj[origin][destin] = 1;
			adj[destin][origin]=1;
			disi[origin][destin]=w;
			disi[destin][origin]=w;
		}
	}/*End of for*/
}/*End of create_graph()*/
