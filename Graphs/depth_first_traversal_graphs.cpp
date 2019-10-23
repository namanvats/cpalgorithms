//Graph Traversal Algorithm
//Depth First Traversal algorithm to traverse all nodes of a graph
//Assumption: Graph has only one component and undirected
//Language Used: C++
//author:goyaldhara
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
ll visit[100000];
vector<ll> vec[10000];
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
	cout<<s<<'\n';
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
	int source;
	cin>>source;
	dfs(source);
	return 0;
}