#include<bits/stdc++.h>
using namespace std;

vector<long long int>cost(100001,0);
long long int indexi=1;

long long int dfs(vector<vector<long long int> >&g,vector<long long int>&visited,long long int i,vector<vector<long long int> >&teams)
{
	visited[i]=indexi;
	teams[indexi].push_back(i);
	long long int j;
	for(j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==0)
		{
			dfs(g,visited,g[i][j],teams);
		}
	} 
}

int main()
{

	long long int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		long long int n,m;
		cin>>n>>m;
		long long int i,j;
		vector<vector<long long int> >g(n+1);
		vector<vector<long long int> >teams(n+1);

		for(i=0;i<m;i++)
		{
			long long int temp1,temp2;
			cin>>temp1>>temp2;
			g[temp1].push_back(temp2);
			g[temp2].push_back(temp1);
		}
		for(i=1;i<=n;i++)
		{
			cin>>cost[i];
		}
		vector<long long int>visited(n+1,0);
		indexi=1;
		for(i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				dfs(g,visited,i,teams);
				
				indexi++;

			}
		}
		//cout<<maxcountindex<<" "<<maxcount<<endl;
		long long int ans=0;
		for(i=1;i<=n;i++)
		{
			long long int counti=0;

			for(j=0;j<teams[i].size();j++)
			{
				//cout<<teams[i][j]<<" ";
				counti=counti+cost[teams[i][j]];
			}
			ans=max(ans,counti);
		
		}

		cout<<ans<<endl;
	}

}