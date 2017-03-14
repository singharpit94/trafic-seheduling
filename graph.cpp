#include<bits/stdc++.h>
using namespace std;
#define V 8
#define mak 999

int  adj[V][V];
int dist[V][V];
int main()
{
	adj[0][1]=1;
	adj[1][0]=1;
	
	 srand (time(NULL));
	for(int i=2;i<V;i++)
	{
       int k =rand() % i;
      // cout<<k<<endl;
       adj[i][k]=1;
       adj[k][i]=1;

	}
	int s=7;
	while(s>0)
	{
		int u=rand() % 8;
		int v=rand() % 8;
		//cout<<u<<" "<<v<<endl;
		if(u!=v)
		{
			if(adj[u][v]!=1)
			{
				s--;
				adj[u][v]=1;
				adj[v][u]=1;
			}
		}
	}
	

	for(int i=0;i<8;i++)
    {
    	for(int j=0;j<8;j++)
    	{
    	dist[i][j]=999;

    	}
    	
    }
	  for(int i=0;i<8;i++)
    {
    	for(int j=0;j<8;j++)
    	{
    		if(j>i && adj[i][j]!=0)
    		{
    			int z=rand() % 30;
    			dist[i][j]=z;
    			dist[j][i]=z;
    		}
    	}
    	
    }
    for(int i=0;i<8;i++)
    {
    	for(int j=0;j<8;j++)
    	{
    		cout<<dist[i][j]<<" ";

    	}
    	cout<<"\n";
    }

	return 0;
}