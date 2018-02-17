#include<bits/stdc++.h>
using namespace std;

int ans=INT_MAX;
int dfs(vector<vector<int> >&a,vector<int>&visited,int i,int parent)
{
	if(visited[i]==0)
	{	
		//cout<<"parent= "<<parent<<" "<<i<<endl;

		visited[i]=1;
		int j;
		for(j=1;j<a[i].size();j++)
		{
			if(visited[a[i][j]]==0)
			{
				
				dfs(a,visited,a[i][j],i);
			}

			if(parent!=-1 && binary_search(a[a[i][j]].begin(),a[a[i][j]].end(),parent))
			{
				
				ans=min(ans,(int)(a[i].size()+a[a[i][j]].size()+a[parent].size()-6-3));
			}
		}
	}

}

int main()
{

	int n,m,i,j;
	cin>>n>>m;

	vector<vector<int> >a(40001+1);
	for(i=0;i<=n;i++)
		a[i].push_back(0);
	for(i=0;i<m;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		a[temp1].push_back(temp2);
		a[temp2].push_back(temp1);

	}

	for(i=1;i<=n;i++)
	{
		sort(a[i].begin(),a[i].end());
		/*for(j=0;j<a[i].size();j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<a[i].size();
		cout<<endl;*/		
	}
	vector<int>visited(n+1,0);
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			dfs(a,visited,i,-1);
		}
	}
	cout<<ans<<endl;
	/*for(i=1;i<=n;i++)
		cout<<visited[i];*/
}