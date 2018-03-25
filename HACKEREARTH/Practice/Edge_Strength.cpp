#include<bits/stdc++.h>
using  namespace std;


vector<long long int>numb(100001,1);

long long int dfs(vector<vector<long long int> >&g,vector<long long int>&visited,long long int i,long long int level)
{

	long long int j;
	visited[i]=level;
	for(j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==0)
		{
			dfs(g,visited,g[i][j],level+1);
			numb[i]+=numb[g[i][j]];
		}
	}

}

int main()
{
	long long int n;
	cin>>n;
	long long int temp1,temp2;
	cin>>temp1>>temp2;
	vector<vector<long long int> >g(n+1);
	long long int i;
	vector<vector<long long int> >q(n+1);
	for(i=0;i<n-1;i++)
	{
		cin>>temp1>>temp2;
		q[i].push_back(temp1);
		q[i].push_back(temp2);
		g[temp1].push_back(temp2);
		g[temp2].push_back(temp1);
	}

	vector<long long int>visited(n+1,0);
	dfs(g,visited,1,1);

	/*for(i=1;i<=n;i++)
		cout<<numb[i]<<" ";
	cout<<endl;
	*/
	for(i=0;i<n-1;i++)
	{
		long long int x,y;
		x=q[i][0],y=q[i][1];
		if(visited[x]>visited[y])
		{
			long long int temp=x;
			x=y;
			y=temp;
		}

		cout<<numb[y]*(n-numb[y])<<endl;//" "<<numb[y]<<" "<<n-numb[y]<<endl;
	}
}