#include<bits/stdc++.h>
using namespace std;
vector<int>cost(100005);
vector<int>level(100005);
vector<int>intime(100005);
vector<int>outtime(100005);

int timei=0;

int dfs(vector<vector<int> >&g,vector<int>&visited,int i,int l,vector<vector<int> >&nodes_level_intime,vector<vector<long long int> >&nodes_level_values)
{
	timei++;
	visited[i]=l;
	intime[i]=timei;

	nodes_level_intime[l].push_back(intime[i]);
	nodes_level_values[l].push_back(cost[i]);
	
	int j;
	for(j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==0)
		{
			dfs(g,visited,g[i][j],l+1,nodes_level_intime,nodes_level_values);
		}
	}
	timei++;
	outtime[i]=timei;
}



 int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int it,test;
	//cin>>test;
	scanf("%d",&test);
	for(it=0;it<test;it++)
	{
		/*fill(cost.begin(),cost.end(),0);
		fill(intime.begin(),intime.end(),0);
		fill(outtime.begin(),outtime.end(),0);*/
		timei=0;


		int n,q,i,j;
		//cin>>n>>q;
		scanf("%d%d",&n,&q);
		/*for(i=1;i<=n;i++)
		{
			nodes_level_intime[i].clear();
			nodes_level_values[i].clear();
		}*/
		vector<vector<int> >nodes_level_intime(n+1);
		vector<vector<long long int> >nodes_level_values(n+1);


		for(i=1;i<=n;i++)
		{
			cin>>cost[i];
		}
		vector<vector<int> >g(n+1);
		for(i=0;i<n-1;i++)
		{
			int temp1,temp2;
			cin>>temp1>>temp2;
			g[temp1].push_back(temp2);
			g[temp2].push_back(temp1);
		}
		vector<int>visited(n+1,0);
		dfs(g,visited,1,1,nodes_level_intime,nodes_level_values);
		for(i=1;i<=n;i++)
		{	
		for(j=1;j<nodes_level_values[i].size();j++)
			{
				nodes_level_values[i][j]+=nodes_level_values[i][j-1];
			}
		}

		/*for(i=1;i<=n;i++)
		{
			cout<<intime[i]<<" "<<outtime[i]<<" "<<visited[i]<<endl;
		}*/
		/*for(i=1;i<=n;i++)
		{
			for(j=0;j<nodes_level_values[i].size();j++)
			{
				//cout<<i<<" "<<nodes_level_values[i][j]<<" "<<nodes_level_intime[i][j]<<endl;
				cout<<nodes_level_values[i][j]<<" ";
			}
			cout<<endl;
		}*/
		

		for(i=0;i<q;i++)
		{
			int temp1,temp2;
			cin>>temp1>>temp2;

			int l=visited[temp1];
			
			int left=lower_bound(nodes_level_intime[temp2].begin(),nodes_level_intime[temp2].end(),intime[temp1])-nodes_level_intime[temp2].begin();			
			int right=lower_bound(nodes_level_intime[temp2].begin(),nodes_level_intime[temp2].end(),outtime[temp1])-nodes_level_intime[temp2].begin();
			//cout<<endl<<temp2<<" left="<<left<<" right="<<right<<endl;
			left--,right--;			
			//cout<<endl<<temp2<<" left="<<left<<" right="<<right<<endl;
			if(right<0)
			{	
				//cout<<"0"<<endl;
				printf("0\n");
			}
			else if(left<0)
			{	
				//cout<<nodes_level_values[temp2][right]<<endl;
				printf("%lld\n",nodes_level_values[temp2][right] );
			}
			else 
			{	
				//cout<<nodes_level_values[temp2][right]-nodes_level_values[temp2][left]<<endl;
				printf("%lld\n", nodes_level_values[temp2][right]-nodes_level_values[temp2][left]);
			}			

		}				
	}


}