#include<bits/stdc++.h>
using  namespace std;

vector<int>color(1000000+1);
int k;
vector<vector<int> >arr(1000000+1); 
vector<int>ans(1000000+1);

int dfs(vector<vector<int> >&g,vector<int>&visited,int i)
{

	//cout<<i<<endl;
	visited[i]=1;
	int j;
	if(arr[color[i]].size()>k)
	{
		//cout<<"hello"<<i<<" ";
		ans[i]=arr[color[i]][arr[color[i]].size()-k-1];
		//cout<<ans[i]<<endl;
	}
	else
	{
		ans[i]=-1;
	}

	for(j=0;j<g[i].size();j++)
	{

		if(visited[g[i][j]]==0)
		{
			arr[color[g[i][j]]].push_back(g[i][j]);
			dfs(g,visited,g[i][j]);
			arr[color[g[i][j]]].pop_back();
		}
	}

}


int main()
{

	int n;
	int i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>color[i];
	}
	vector<vector<int> >g(n+1);
	for(i=0;i<n-1;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		g[temp2].push_back(temp1);
		g[temp1].push_back(temp2);
	}

	vector<int>visited(n+1,0);
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			arr[color[i]].push_back(i);
			dfs(g,visited,i);
			arr[color[i]].pop_back();

		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}