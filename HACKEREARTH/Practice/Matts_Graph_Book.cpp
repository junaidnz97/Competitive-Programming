#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> >&g,vector<int>&visited,int i)
{

	visited[i]=1;
	int j;
	//cout<<i<<endl;
	for(j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==0 && g[i][j]!=-1)
		{
			dfs(g,visited,g[i][j]);
		}
	}
}

int main()
{
	int n,m;

	cin>>n>>m;

	int i,j;

	vector<vector<int> >g(n+1);
	int temp1,temp2;
	for(i=0;i<m;i++)
	{

		cin>>temp1>>temp2;
		g[temp1].push_back(temp2);
		g[temp2].push_back(temp1);
	}

	int v;
	cin>>v;
	g[v].clear();
	for(i=0;i<n;i++)
	{
		for(j=0;j<g[i].size();j++)
		{
			if(g[i][j]==v)
				g[i][j]=-1;
		}
	}
	
	int flag=0;
	vector<int>visited(n+1,0);
	for(i=0;i<n;i++)
	{
		if(visited[i]==0 && i!=v)
		{
			if(flag==1)
			{
				flag=0;
				cout<<"Not Connected";
				break;
			}
			dfs(g,visited,i);
			
		}
		if(i!=v)
			flag=1;
	}
	if(flag==1)
		cout<<"Connected"<<endl;
}