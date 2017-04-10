#include<bits/stdc++.h>
using namespace std;
#define V 30
#define mak 999

int  adj[V][V];
int dist[V][V];
int main()
{
	 ofstream myfile;
      ofstream myfile1;
	 ifstream input;
    myfile.open ("adj1.txt");
    myfile1.open("random.txt");
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
	int s=100;
	while(s>0)
	{
		int u=rand() % V;
		int v=rand() % V;
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
	

	for(int i=0;i<V;i++)
    {
    	for(int j=0;j<V;j++)
    	{
    	dist[i][j]=999;

    	}
    	
    }
	  for(int i=0;i<V;i++)
    {
    	for(int j=0;j<V;j++)
    	{
    		if(j>i && adj[i][j]!=0)
    		{
    			int z=rand() % 200;
    			dist[i][j]=z;
    			dist[j][i]=z;
    		}
    	}
    	
    }
    // for(int i=0;i<V;i++)
    // {
    // 	for(int j=0;j<V;j++)
    // 	{
    // 		cout<<dist[i][j]<<" ";

    // 	}
    // 	cout<<"\n";
    // }
    for(int i=0;i<V;i++)
    {
    	for(int j=0;j<V;j++)
    	{
    		myfile<<dist[i][j]<<" ";

    	}
    	myfile<<"\n";
    }
    int z=5;
    myfile<<z<<"\n";
    while(z--)
    {
            int u=rand() % V;
            int v=rand() % V;
        //cout<<u<<" "<<v<<endl;
        if(u!=v)
        {
            myfile<<u<<"\n";
            myfile<<v<<"\n";
        }
        
    }
     for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            myfile1<<adj[i][j]<<" ";

        }
        myfile1<<"\n";
    }
     for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            myfile1<<dist[i][j]<<" ";

        }
        myfile1<<"\n";
    }
    int z1=5;
     myfile1<<z1<<"\n";
    while(z1--)
    {
            int u=rand() % V;
            int v=rand() % V;
        //cout<<u<<" "<<v<<endl;
        if(u!=v)
        {
            myfile1<<u<<"\n";
            myfile1<<v<<"\n";
        }
        
    }

   

	return 0;
}