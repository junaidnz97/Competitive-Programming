#include<bits/stdc++.h>
using namespace std;

long long int counto,counte;


long long int dfs(vector<vector<long long int> >&a,vector<long long int>&visited,long long int i,long long int x,vector<long long int>&present)
{
	if(visited[i]==0 && present[i]==1)
	{
		visited[i]=1;
		if(x%2==0)
			counte++;
		else
			counto++;
		long long int j;
		for(j=0;j<a[i].size();j++)
		{
			if(visited[a[i][j]]==0 && present[a[i][j]]==1)
			{
				dfs(a,visited,a[i][j],x+1,present);
			}
		}
	}
}
int main()
{


	long long int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		long long int n;
		cin>>n;
		vector<vector<long long int> >a(20001);
		vector<long long int >present(20001,0);
		long long int i,j;
		long long int temp1,temp2;
		for(i=0;i<n;i++)
		{
			cin>>temp1>>temp2;
			a[temp1].push_back(temp2);
			a[temp2].push_back(temp1);
			present[temp2]=1;
			present[temp1]=1;
			
		}
		
		vector<long long int>visited(20001,0);
		long long int ans=0;
		for(i=1;i<=20000;i++)
		{
			if(visited[i]==0 && present[i]==1)
			{
				counte=0,counto=0;
				dfs(a,visited,i,0,present);
				ans+=max(counte,counto);
			}

		}
		
		cout<<"Case "<<it+1<<": "<<ans<<endl;


	}
}