#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> >&arr,vector<int>&visited,int i,int n,vector<int>&depth,int k)
{
	if(visited[i]==0)
	{	
		depth[i]=k;
		visited[i]=1;
		int j;
		for(j=1;j<=n;j++)
		{
			if(visited[j]==0 && arr[i][j]==1)
			{
				dfs(arr,visited,j,n,depth,k+1);
			}
		}
	}
}

int main()
{

	int n,i;
	cin>>n;
	vector<vector<int> > arr(n+1,vector<int>(n+1,0));
	for(i=0;i<n-1;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		arr[temp1][temp2]=1;
		arr[temp2][temp1]=1;
	}
	vector<int>visited(n+1,0);
	
	int q;
	cin>>q;
	vector<int>girls(q,0);
	vector<int>depth(n+1,0);
	for(i=0;i<q;i++)
	{
		int temp;
		cin>>temp;
		girls[i]=temp;
	}
	dfs(arr,visited,1,n,depth,0);
	//for(i=1;i<=n;i++)
	//	cout<<depth[i]<<" ";
	int mini=INT_MAX,ans=-1;
	for(i=0;i<q;i++)
	{	
		if(mini>depth[girls[i]])
		{	
			mini=depth[girls[i]];
			ans=girls[i];

		}
		if(mini==depth[girls[i]])
		{
			ans=min(ans,girls[i]);
		}
	}
	cout<<ans<<endl;
}