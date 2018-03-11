#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >dp(100002,vector<int>(26,0));
vector<char>s(100002,0);


int dfs(vector<vector<int> >&g,vector<int>&visited,int i)
{

	visited[i]=1;
	int j,k;
	dp[i][s[i]-'a']+=1;


	for(j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==0)
		{
			dfs(g,visited,g[i][j]);
			for(k=0;k<26;k++)
			{
				dp[i][k]+=dp[g[i][j]][k];
			}
		}
		
	}

}


int main()
{


	int n,q;

	cin>>n>>q;

	int i,j;
	for(i=1;i<=n;i++)
	{

		cin>>s[i];
	}

	vector<vector<int> >g(n+1);
	int temp1,temp2;
	for(i=1;i<=n-1;i++)
	{

		cin>>temp1>>temp2;
		g[temp1].push_back(temp2);
		g[temp2].push_back(temp1);
	}

	vector<int>visited(n+1,0);
	dfs(g,visited,1);

	/*for(char x='a';x<='z';x++)
		cout<<x<<" ";
	
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/

	string temp;
	for(i=0;i<q;i++)
	{
		cin>>temp1>>temp;
		//cout<<temp1<<" "<<temp<<endl;
		vector<int>arr(26,0);
		for(j=0;j<temp.size();j++)
		{
			arr[temp[j]-'a']++;
		}
		
		int finans=0;
		for(j=0;j<26;j++)
		{
			if(dp[temp1][j]-arr[j]<0)
			{
				finans=finans-dp[temp1][j]+arr[j];
			}
		}
		cout<<finans<<endl;
	}


}