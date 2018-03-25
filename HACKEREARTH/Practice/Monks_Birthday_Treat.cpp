#include<bits/stdc++.h>
using namespace std;

int maxi=INT_MAX;
int counti=0;
vector<int>finvisit(10001,0);
int dfs(vector<vector<int> >&g,vector<int>&visited,int i)
{
	counti++;
	finvisit[i]=1;
	visited[i]=1;
	for(int j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==0)
		{
			dfs(g,visited,g[i][j]);
		}
	}

}

int main()
{
	int n,d;
	cin>>n>>d;

	int i,j;;
	vector<vector<int> >g(n+1);
	int temp1,temp2;
	for(i=0;i<d;i++)
	{
		cin>>temp1>>temp2;
		g[temp1].push_back(temp2);
	}

	for(i=1;i<=n;i++)
	{
		vector<int>visited(n+1,0);
		counti=0;		
		dfs(g,visited,i);
		maxi=min(counti,maxi);
		//cout<<counti<<endl;
	}
	int flag=0;
	for(i=1;i<=n;i++)
	{
		if(finvisit[i]==0)
		{
			flag=1;
			cout<<"1"<<endl;
			break;
		}
	}
	if(flag==0)
	cout<<maxi<<endl;
}