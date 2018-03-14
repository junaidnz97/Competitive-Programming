#include<bits/stdc++.h>
using  namespace std;

#define mod 1000000007

vector<long long int>cost(100005,0);
long long int counti=0,maxi=0;

vector<vector<long long int> >connect(100005);
long long int indexi=1;

long long int dfs(vector<vector<long long int> >&g,vector<long long int>&visited,long long int i)
{
	connect[indexi].push_back(i);
	
	visited[i]=indexi;
	long long int j;
	if(maxi<cost[i])
	{
		maxi=cost[i];
		counti=1;
	}
	else if(maxi==cost[i])
	{
		counti++;
	}

	for(j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==0)
		{
			dfs(g,visited,g[i][j]);
		}

	}
}

int main()
{


	long long int n,m;
	cin>>n>>m;

	long long int i,j;
	vector<long long int>visited(n+1,0);

	for(i=1;i<=n;i++)
	{
		cin>>cost[i];
	}

	//cout<<"\thello"<<endl;
	vector<vector<long long int> >g(n+1);
	long long int temp1,temp2;
	
	for(i=0;i<m;i++)
	{
		cin>>temp1>>temp2;
		g[temp1].push_back(temp2);
		g[temp2].push_back(temp1);
	}

	long long int ans=1;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0 && g[i].size()>0)
		{
			counti=0;maxi=INT_MIN;
			dfs(g,visited,i);
			indexi++;
			//cout<<counti<<endl;
			ans=(ans*counti)%mod;
			//cout<<ans<<endl;
		}
	}
	cout<<ans<<endl;
/*	for(i=1;i<=n;i++)
	cout<<visited[i]<<" ";
	cout<<endl;*/
	/*for(i=1;i<indexi;i++)
	{
		sort(connect[i].begin(),connect[i].end());
		for(j=0;j<connect[i].size();j++)
		{
			cout<<connect[i][j]<<" ";
		}
		cout<<endl;
		long long int ub=upper_bound(connect[i].begin(),connect[i].end(),connect[i][connect[i].size()-1])-connect[i].begin();
		long long int lb=lower_bound(connect[i].begin(),connect[i].end(),connect[i][connect[i].size()-1])-connect[i].begin();
		cout<<ub<<" "<<lb<<endl;
	//	ans=(ans*(ub-lb))%mod;
	}*/
	//cout<<ans<<endl;
}
