#include<bits/stdc++.h>
using namespace std;

int ans=0;
int con_no=1;
vector<int>con_size(100002,0);
vector<int>conv(100002,0);
vector<int>lowtime(100002,-1);
vector<int>intime(100002,-1);
vector<int>sz(100002,1);

int timein=0;
int no_links=0;
int p;

int dfs1(vector<vector<int> >&g,vector<int>&visited,int i,int parent)
{
	int j;
	visited[i]=1;
	conv[i]=con_no;
	con_size[con_no]++;
	
	for(j=0;j<g[i].size();j++)
	{
		
		
		if(visited[g[i][j]]==0)
		{
			dfs1(g,visited,g[i][j],i);
			sz[i]+=sz[g[i][j]];

		}
		
	}


}

int x=0;

int dfs2(vector<vector<int> >&g,vector<int>&visited,int i,int parent)
{

	int j;
	timein++;
	intime[i]=timein;
	lowtime[i]=timein;
	visited[i]=1;
	for(j=0;j<g[i].size();j++)
	{
		if(g[i][j]==parent)continue;
		
		if(visited[g[i][j]]==0)
		{
			dfs2(g,visited,g[i][j],i);
		}

		lowtime[i]=min(lowtime[i],lowtime[g[i][j]]);

		if(intime[i]<lowtime[g[i][j]])
		{
			
			if(abs(sz[g[i][j]]-(con_size[conv[g[i][j]]]-sz[g[i][j]]))<p)
			{	
				no_links++;
				//cout<<abs(sz[g[i][j]]-(con_size[conv[i]]-sz[g[i][j]]))<<" "<<++x<<" "<<p<<endl;
			}

		}

	}


}


int main()
{

	int n,m;
	cin>>n>>m>>p;
	vector<vector<int> >g(n+1);
	int i,temp1,temp2;
	for(i=0;i<m;i++)
	{
		cin>>temp1>>temp2;
		g[temp1].push_back(temp2);
		g[temp2].push_back(temp1);
	}
	vector<int>visited(n+1,0);
	con_no=0;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			dfs1(g,visited,i,-1);
			con_no++;
		}
	}

	/*for(i=1;i<=n;i++)
	{
		cout<<conv[i];
	}
	cout<<endl;
	for(i=1;i<=con_no;i++)
	{
		cout<<con_size[i]<<" ";
	}*/
	fill(visited.begin(),visited.end(),0);
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			dfs2(g,visited,i,-1);
			
		}
	}
	cout<<no_links<<endl;
}