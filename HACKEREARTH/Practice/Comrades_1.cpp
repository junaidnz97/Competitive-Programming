#include<bits/stdc++.h>
#include<stdio.h>
using  namespace std;


int timei=0;
vector<int>intime(1000001,0);
vector<int>outtime(1000001,0);

int dfs(vector<vector<int> >&g,vector<int>&visited,int i,int level)
{

	timei++;
	intime[i]=timei;

	int j;
	visited[i]=level;

	for(j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==0)
		{
			dfs(g,visited,g[i][j],level+1);
		}
	}
	timei++;
	outtime[i]=timei;

}

int main()
{

	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{

		int n,i,j;
		//cin>>n;
		scanf("%d",&n);
		vector<vector<int> >g(n+1);
		int start=0;
		for(i=1;i<=n;i++)
		{
			int temp;
			scanf("%d",&temp);
			g[temp].push_back(i);
			g[i].push_back(temp);
		}

		int q;
		/*for(i=0;i<=n;i++)
		{
			for(j=0;j<g[i].size();j++)
			{
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}*/
			
		vector<int>visited(n+1,0);
		visited[0]=1;
		dfs(g,visited,g[0][0],1);

		/*for(i=1;i<=n;i++)
		{
			cout<<intime[i]<<" "<<outtime[i]<<" "<<visited[i]<<endl;
		}*/

		//cin>>q;
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{	
			int temp1,temp2;
			//cin>>temp1>>temp2;
			scanf("%d%d",&temp1,&temp2);
			if(intime[temp2]<intime[temp1] && outtime[temp2]>outtime[temp1])
			{

				//cout<<visited[temp1]-visited[temp2]-1<<endl;
				printf("%d\n",visited[temp1]-visited[temp2]-1);
			}
			else
			{
				//cout<<"-1"<<endl;
				printf("-1\n");
			}

		}

	}


}