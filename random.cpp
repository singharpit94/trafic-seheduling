#include<bits/stdc++.h>
using namespace std;
#define V 5
#define INF 99999
#define MAX 100  

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

struct distances nodes[V];
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
int main()
{   
    srand (time(NULL));
	int max_seg=0;
	int t,s1=0,d1=0,k1,k2,p1,p2,now;
    int s[50];
    int d[50];
    int curr[50];
    for(int i=0;i<V;i++)
    {
    	junc[i].lvi=0;
    	junc[i].slvi=0;
    }
    //create_graph();
    adj[0][1] = 1;
    adj[1][0] = 1;
   adj[0][2]=1;
   adj[2][0]=1;
   adj[1][2]=1;
   adj[2][1]=1;
   adj[1][3]=1;
   adj[3][1]=1;
   adj[2][4]=1;
   adj[4][2]=1;
   adj[2][3]=1;
   adj[3][2]=1;
   adj[3][4]=1;
   adj[4][3]=1;
    disi[0][1] = 3;
    disi[1][0] = 3;
   disi[0][2]=4;
   disi[2][0]=4;
   disi[1][2]=5;
   disi[2][1]=5;
   disi[1][3]=6;
   disi[3][1]=6;
   disi[2][4]=9;
   disi[4][2]=9;
   disi[2][3]=7;
   disi[3][2]=7;
   disi[3][4]=8;
   disi[4][3]=8;
    

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

     cout<<max_seg<<endl;

    for(int i=1;i<max_seg;i++){

    	for(int j=0;j<s1;j++)
    	{
              if(i==1)
              {
                     now=s[j];
                     cout<<now<<endl;
                     cout<<d[j]<<endl;
                   
                   

              }
              else
              {
                            now=curr[j];
                            cout<<now<<endl;
                            cout<<d[j]<<endl;
              }
                    if(now!=d[j])
                    {
                                 int len=nodes[now].dis[d[j]].route.size();

                    int isSecret=rand() % len;
                   //cout<<isSecret<<endl;
                    int len1=nodes[now].dis[d[j]].route[isSecret].size();
                    cout<<"Route Selected\n";
                    for(int z=0;z<len1;z++)
                    {
                    	cout<<nodes[now].dis[d[j]].route[isSecret][z]<<" ";
                    }
                    cout<<endl;
                    k1=junc[now].slvi;
                    k2=junc[nodes[now].dis[d[j]].route[isSecret][1]].slvi;
                    p1=now;
                    p2=nodes[now].dis[d[j]].route[isSecret][1];
                    //cout<<k1<<" "<<k2<<endl;
                    //cout<<p1<<" "<<p2<<endl;
                    if(k1==0 && k2==0)
                    {
                    	junc[p2].lvi=disi[p1][p2]+k1;
                    }
                    else if(k1==k2)
                    {
                              if(p2>p1)
                              {
                              	junc[p2].lvi=disi[p1][p2]+k1;
                              }
                              else
                              {
                              	junc[p2].lvi=2*disi[p1][p2]+k1;
                              }
                    }
                    else if(k1<k2)
                    {
                    	junc[p2].lvi=disi[p1][p2]+k1;
                    }
                    else if(k1>k2)
                    {
                               if((k2+disi[p1][p2])<k1)
                               {
                               	junc[p2].lvi=disi[p1][p2]+k1;
                               }
                               else
                               {
                               	junc[p2].lvi=2*disi[p1][p2]+k1;
                               }
                    }

                       curr[j]=p2;
              
    	}
                    }
               
               cout<<"Nodes Values after  "<<i<<"  iterations\n";
    	for(int j=0;j<V;j++)
    {   

       
        cout<<"Node "<<j<<" ---  "<<junc[j].lvi<<endl;
        junc[j].slvi=junc[j].lvi;
    }
    }
    
   
    
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
