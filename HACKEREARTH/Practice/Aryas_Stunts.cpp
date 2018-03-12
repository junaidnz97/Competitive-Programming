#include<bits/stdc++.h>
using  namespace std;


vector<int>warriors(10001);
int maxs=0,sums=0,id=0;

int dfs(vector<vector<int> >&g,vector<int>&visited,int i)
{

	visited[i]=1;
	sums=sums+warriors[i];
	//cout<<i<<endl;
	if(maxs<warriors[i])
	{
		maxs=warriors[i];
		id=i;
	}
	else if(maxs==warriors[i])
	{
		id=min(id,i);
	}

	int j;
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

	int n,m;
	cin>>n>>m;

	int i;
	vector<int>visited(n+1,0);

	for(i=1;i<=n;i++)
	{
		cin>>warriors[i];
	}

	vector<vector<int> >g(n+1);
	int temp1,temp2;
	
	for(i=0;i<m;i++)
	{
		cin>>temp1>>temp2;
		g[temp1].push_back(temp2);
		g[temp2].push_back(temp1);
	}

	int died=0,injured=0;
	vector<int>burnedid;

	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			 maxs=0,sums=0,id=0;
			dfs(g,visited,i);
			//cout<<maxs<<" "<<id<<endl;
			died+=maxs;
			injured+=sums-maxs;
			burnedid.push_back(id);
			
		}
	}
	cout<<died<<" "<<injured<<endl;
	sort(burnedid.begin(),burnedid.end());
	for(i=0;i<burnedid.size();i++)
	{
		cout<<burnedid[i]<<" ";
	}
	cout<<endl;


}