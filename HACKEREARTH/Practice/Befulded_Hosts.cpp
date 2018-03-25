#include<bits/stdc++.h>
using  namespace std;


long long int counti=0;
vector<long long int>arr(1000000,0);

long long int dfs(vector<vector<long long int> >&g,vector<long long int>&visited,long long int i)
{
	arr[counti]++;
	//cout<<counti<<" "<<i<<" "<<arr[counti]<<endl;

	long long int j;
	visited[i]=1;
	for(j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==0)
		{
			dfs(g,visited,g[i][j]);
		}
	}

}

long long int sum1()
{
	long long int i;
	long long int ans=0;
	for(i=0;i<counti;i++)
		ans+=arr[i];
	return ans*ans;
}

long long int sum2()
{
	long long int i;
	long long int ans=0;
	for(i=0;i<counti;i++)
		ans+=arr[i]*arr[i];
	return ans;	
}

int main()
{

	long long int n,p;
	cin>>n>>p;
	long long int i;
	vector<vector<long long int> >g(n+1);
	for(i=0;i<p;i++)
	{
		long long int temp1,temp2;
		cin>>temp1>>temp2;
		g[temp1].push_back(temp2);
		g[temp2].push_back(temp1);
	}

	vector<long long int>visited(n+1,0);
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs(g,visited,i);
			counti++;
		}
	}
	//for(i=0;i<counti;i++)
	//	cout<<arr[i]<<" ";
	//cout<<endl;
	long long int ans=0;
	if(counti>1)
	{
		ans=(sum1()-sum2())/2;
		cout<<ans<<endl;
	}
	else
	{
		cout<<"0"<<endl;
	}

}