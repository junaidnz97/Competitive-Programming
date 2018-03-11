#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int timer=0;
vector<int>visited(200001,0);
vector<int>intime(200001 ,0);
vector<int>outtime(200001 ,0);
int dfs(vector<vector<int> >&g,int i)
{

			visited[i]=1;
			timer++;
			intime[i]=timer;
			int j;
			for(j=0;j<g[i].size();j++)
			{
				if(visited[g[i][j]]==0)
				{
					dfs(g,g[i][j]);
				}
			}
			timer++;
			outtime[i]=timer;
}


int main()
{
	ios_base::sync_with_stdio(false);
	

	int n,q;
	cin>>n>>q;

	int i;
	vector<vector<int> >g(200001);
	for(i=0;i<n-1;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		//scanf("%d%d",&temp1,&temp2);
		g[temp1].push_back(temp2);
		g[temp2].push_back(temp1);
	}
		int temp1,temp2;
	/*for(i=0;i<q;i++)
	{
		
		
		query[i][0]=temp1;
		query[i][1]=temp2;

	}*/

	

	/*for(i=1;i<n;i++)
	{

		if(visited[i]==0)
		{
			dfs(g,visited,i,intime,outtime);
		}
	}*/

	dfs(g,1);

	for(i=0;i<q;i++)
	{
		cin>>temp1>>temp2;
		//temp1=query[i][0];
		//temp2=query[i][1];

		if((intime[temp1]>intime[temp2] && outtime[temp1]<outtime[temp2])||(intime[temp1]<intime[temp2] && outtime[temp1]>outtime[temp2]) )
			printf("YES\n");
		else
			printf("no\n");	
	}

}