#include <bits/stdc++.h>
using namespace std;

int ans;
int x;

int dfs(vector<vector<int> >&a,vector<int>&visited,int i)
{
	if(visited[i]==0)
	{
		visited[i]=1;
		int j;
		for(j=0;j<a[i].size();j++)
		{	

			if(visited[a[i][j]]==0)
			{	
				if(x==0)
				{
					x=1;
					if(a[i].size()<a[a[i][j]].size()-1)
						ans++;
				}
			
			//cout<<a[i].size()<<" "<<a[a[i][j]].size()<<endl;
				else
				{
					if(a[i].size()<a[a[i][j]].size())
						ans++;
			
				}
				dfs(a,visited,a[i][j]);
			}
		}
	}

}


int main()
{
	ans=0;
	int n,m;
	cin>>n>>m;
	vector<vector<int> >a(n+1);
	int i,j;
	for(i=0;i<m;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		a[temp1].push_back(temp2);
		a[temp2].push_back(temp1);
	}

	/*for(i=1;i<=n;i++)
	{
		for(j=0;j<a[i].size();j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}*/
	vector<int>visited(n+1,0);
	
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0);
		{	
			x=0;
			dfs(a,visited,i);
		}
	}
	cout<<ans<<endl;
}