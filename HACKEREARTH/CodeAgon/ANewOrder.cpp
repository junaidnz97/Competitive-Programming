#include<bits/stdc++.h>
using namespace std;

stack <char> s;

void dfs(vector<vector<int> >&b,int i,vector<int>&visited,int r,vector<int>&rank)
{

	
		
		visited[i]=1;
		int j;
		stack <char> temp;
		for(j=0;j<26;j++)
		{
			if(visited[j]==0 && b[i][j]==1)
			{
				dfs(b,j,visited,r+1,rank);
			
			}	
			if(b[i][j]==1)
			{
				if(rank[j]<r+1)
				{
					rank[j]=r+1;
					dfs(b,j,visited,r+1,rank);
				}
			}
		}
		
	
	
}

int main()
{

	int w;
	char a[100][20];
	cin>>w;

	int i,j;
	for(i=0;i<w;i++)
	{
		cin>>a[i];
	}
	
	vector<vector<int> >b(26,vector<int>(26,0));

	
	vector<int>visited(26,-1);

	for(i=0;i<w-1;i++)
	{
		for(j=0; j<strlen(a[i]) && j<strlen(a[i+1]);j++)
		{

			visited[a[i][j]-'a']=0;
			visited[a[i+1][j]-'a']=0;
			if(a[i][j]!=a[i+1][j])
			{
				b[a[i][j]-'a'][a[i+1][j]-'a']=1;
				break;
			}
		}

	}
	for(i=0;i<w;i++)
	{
		for(j=0;j<strlen(a[i]);j++)
		{
			visited[a[i][j]-'a']=0;
		}
	}
	
	vector<int>noorder(26,0);
	vector<int> rank(26,-1);

	for(i=0;i<26;i++)
	{	

		if(visited[i]==0)
		{	
			rank[i]=1;
			dfs(b,i,visited,1,rank);
		
		}
	}
	

	vector<vector<int> > fin(26);

	for(i=0;i<26;i++)
	{
		if(rank[i]!=-1)
		{
			fin[rank[i]].push_back(i);
		}
	}
	for(i=0;i<26;i++)
	{
		sort(fin[i].begin(),fin[i].end());
		int flag=0;
		for(j=0;j<fin[i].size();j++)
		{
			flag=1;
			cout<<(char)(fin[i][j]+'a');
		}
		if(flag==1)
		{
			cout<<endl;
		}
	}

}