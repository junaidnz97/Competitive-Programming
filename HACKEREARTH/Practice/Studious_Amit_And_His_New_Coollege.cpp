#include<bits/stdc++.h>
using namespace std;

int flag;
int dfs(vector<vector<int> >&g,vector<int>&visited,int i)
{
		int j;
		visited[i]=1;
		for(j=0;j<g[i].size();j++)
		{
			if(visited[g[i][j]]==1)
			{
				flag=1;
				return 0;
			}
			//if(visited[g[i][j]]==0)
			dfs(g,visited,g[i][j]);
		}
		visited[i]=-1;
}

int main()
{

	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		int n,m,i;
		cin>>n>>m;
		int temp1,temp2;

		vector<vector<int> >g(n+1);
		for(i=0;i<m;i++)
		{	
			cin>>temp1>>temp2;
			g[temp1].push_back(temp2);
		
		}

		vector<int>visited(n+1,0);
		flag=0;
		for(i=1;i<=n;i++)
		{	
			if(flag==1)
				break;
			if(visited[i]==0)
			{
				dfs(g,visited,i);
			}
		}
		if(flag==1)
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
	}
}