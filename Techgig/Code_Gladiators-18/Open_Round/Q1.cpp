#include<bits/stdc++.h>
using namespace std;

vector<int>a(200,0),visited(200,0);
vector<vector<int> >g(200);
vector<int> arr_size(200,0);
int x;

int dfs(int i)
{
	int j;
	
	visited[i]=1;
	for(j=0;j<g[i].size();j++)
	{
		if(g[i][j]==-2)
			return 0;
		if(g[i][j]==x)
		{
			g[i][j]=-2;
			return 0;
		}
		if(visited[g[i][j]]==0)
		{
			dfs(g[i][j]);
		}
		
	}	
}

int ans=0;
int dfs2(int i)
{
	if(g[i].size()==0)
		ans++;
	visited[i]=1;	
	if(g[i].size()==1 )
	{
		if(g[i][0]==-2)
			ans++;
	}
	
	int j;
	for(j=0;j<g[i].size();j++)
	{
		if(g[i][j]==-2)
		{
			continue;
		}
		if(visited[g[i][j]]==0)
		{
			dfs2(g[i][j]);
		}
		
	}
}
int main()
{
	int n,i,j;
	cin>>n;
	int root;
	for(i=0;i<n;i++)
	{
			cin>>a[i];
			
			g[a[i]].push_back(i);
			if(a[i]==-1)
				root=i;
	}	
	cin>>x;
	if(x==root)
	{
		cout<<"0";
		return 0;
	}
	
	dfs(root);
	
	for(i=0;i<n;i++)
		visited[i]=0;
		

	dfs2(root);
	cout<<ans<<endl;
}
