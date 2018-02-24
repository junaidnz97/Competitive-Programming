#include <bits/stdc++.h>
using namespace std;


int ans;
int n;
int fun(vector<vector<int> >&a,int i,int j,vector<vector<int> >&visited)
{
	
	if(i==n && j==n)
	{
		
		ans++;
		int p,q;
		
	}

	else
	{

	visited[i][j]=1;
	if(a[i+1][j]==0 && visited[i+1][j]==0 ) 
	{
		fun(a,i+1,j,visited);
	}
	if(a[i][j+1]==0 && visited[i][j+1]==0) 
	{
		fun(a,i,j+1,visited);
	}
	if(a[i][j-1]==0 && visited[i][j-1]==0) 
	{
		fun(a,i,j-1,visited);
	}
	if(a[i-1][j]==0 && visited[i-1][j]==0 ) 
	{
		fun(a,i-1,j,visited);
	}
	visited[i][j]=0;
	}

}

int main()
{
	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		int i,j;
		cin>>n;
		vector<vector<int> > a(n+2,vector<int>(n+2,-1)),visited(n+2,vector<int>(n+2,-1));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>a[i][j];
				visited[i][j]=0;
			}
		}
		/*for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=n+1;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}*/
		ans=0;

		fun(a,1,1,visited);
		cout<<ans<<endl;
	}
}