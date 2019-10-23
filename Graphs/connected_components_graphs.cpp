//Graph Traversal Algorithm
//Depth First Traversal algorithm to count connected components in an undirected Graph
//Assumption: Graph is undirected
//Language Used: C++
//author:goyaldhara
#include<bits/stdc++.h>
using namespace std;
int visit[100000];
vector<int> vec[10000];
void initial()
{
    //This function sets the visit array to zero.
    //Visit array will be used to make sure which nodes have been visited or not.
	for(int i=0;i<100000;i++)
		visit[i]=0;
}
void dfs(int s)
{
	visit[s]=1;
	for(int i=0;i<vec[s].size();i++)
	{
		if(!visit[vec[s][i]])
			dfs(vec[s][i]);
	}
}
int main()
{
	initial();
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
	    int x,y;
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	int cnt=0;
	for(int i=1;i<=nodes;i++)
	{
	    if(visit[i]!=1)
	   {
	       cnt++;
	       //Here we are counting total number of different components in the graph as whenever dfs algorithm
	       //runs, it visits all nodes in that component and we increase the count to acknowledge that component.
	       dfs(i);
	   }
	}
	cout<<cnt<<'\n';
return 0;
}