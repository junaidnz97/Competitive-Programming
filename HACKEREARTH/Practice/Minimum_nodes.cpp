#include<bits/stdc++.h>
using namespace std;

vector<long long int>cost(100001,-1);
long long int num_nodes=INT_MAX;

long long int dfs(vector<vector<long long int> >&g,vector<long long int>&visited,long long int i,long long int sum,long long int k,long long int level)
{
	if(visited[i]==0)
	{
		visited[i]=1;
		long long int j;
		sum+=cost[i];
		if(sum>=k)
			num_nodes=min(num_nodes,level);
		//else
		{
			for(j=0;j<g[i].size();j++)
			{
				if(visited[g[i][j]]==0)
				{
					dfs(g,visited,g[i][j],sum,k,level+1);
				}
			}
		}
	}



}

int main()
{


	long long int n,q,i;
	cin>>n>>q;

	
	long long int temp;
	long long int temp1,temp2;
	for(i=1;i<=n;i++)
	{
		cin>>cost[i];
	}
	
	vector<vector<long long int> >g(n+1);
	for(i=1;i<=n-1;i++)
	{	
		cin>>temp1>>temp2;
		g[temp2].push_back(temp1);
		g[temp1].push_back(temp2);

	}


	for(i=0;i<q;i++)
	{
		cin>>temp1>>temp2;
		vector<long long int>visited(n+1,0);
		num_nodes=INT_MAX;
		dfs(g,visited,temp1,0,temp2,1);
		if(num_nodes==INT_MAX)
			cout<<"-1"<<endl;
		else	
		cout<<num_nodes<<endl;
	}

}