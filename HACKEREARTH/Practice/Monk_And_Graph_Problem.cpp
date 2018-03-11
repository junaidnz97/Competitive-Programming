#include<bits/stdc++.h>
using namespace std;

long long int c=0,max_c=INT_MIN;
long long int dfs(vector<vector<long long int> >&g,vector<long long int>&visited,long long int i,long long int parent)
{
	
	visited[i]=1;
	long long int j;
	//cout<<i<<endl;
	for(j=0;j<g[i].size();j++)
	{
		//if(g[i][j]==parent)
		//	continue;
		if(visited[g[i][j]]==0 )
		{
			dfs(g,visited,g[i][j],i);
			
		}
		//cout<<i<<" "<<g[i][j]<<endl;
		c++;

	}
}
int main()
{
	long long int n,m;

	cin>>n>>m;

	long long int i,j;

	vector<vector<long long int> >g(n+1);
	long long int temp1,temp2;
	for(i=0;i<m;i++)
	{

		cin>>temp1>>temp2;
		
			g[temp1].push_back(temp2);
			g[temp2].push_back(temp1);
		
	}

	vector<long long int>visited(n+1,0);

	for(i=1;i<=n;i++)
	{

		if(visited[i]==0)
		{
			c=0;
			dfs(g,visited,i,-1);
			max_c=max(c/2,max_c);
		}
		//cout<<"hello"<<endl;
	}
	cout<<max_c<<endl;
}