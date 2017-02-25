#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999
#define MAX 100  

struct des{
		vector <vector<int> > route;
	};

struct distances
{
  struct des dis[4];
	
};

struct distances nodes[4];
int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/
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
            	cout << path[i] << " ";
            	nodes[z].dis[d].route[l-1].push_back(path[i]);


        }
             cout << endl;
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
    create_graph();
    for(int i=0;i<4;i++){

    	for(int j=0;j<4;j++)
    {
    	printAllPaths(i,j);
    }
    }
    
    cout<<endl;
    //int l=nodes[0].route.size();
   //  cout<<l<<endl;
    for(int y=0;y<4;y++)
    {
    	for(int i=0;i<4;i++){
    	int l=nodes[y].dis[i].route.size();
        for(int j=0;j<l;j++)
        {
        	int k=nodes[y].dis[i].route[j].size();
        	for(int z=0;z<k;z++)
        		cout<<nodes[y].dis[i].route[j][z]<<" ";
        	   cout<<endl;
        }
    }
    }
    
	return 0;
}
void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

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
		}
	}/*End of for*/
}/*End of create_graph()*/
