#include<bits/stdc++.h>
using namespace std;

int dfs(vector< pair<int,int> >g[],vector< pair<int,int> >g1[],vector<int> &visited,int i,vector<int> &distance1,vector<int> &distance2)
{
   visited[i]=1;
   int j;
   for(j=0;j<g[i].size();j++)
   {
   	 //cout<<"test1";
   	 if(visited[g[i][j].first]!=1)
   	 { // cout<<"hello";
   	 	distance1[g[i][j].first]=distance1[i]+g[i][j].second;
        distance2[g1[i][j].first]=distance2[i]+g1[i][j].second;
   	 	dfs(g,g1,visited,g[i][j].first,distance1,distance2);
   	 }
   }
}

int fun(vector< pair<int,int> >g[],vector<int>&distance1,vector<int>&distance2,int mid,int k,int i,vector<int>&visited)
{
   visited[i]=1;
   int j;
   
   for(j=0;j<g[i].size();j++)
   {
   	 if(visited[g[i][j].first]!=1)
   	 {
   	 	fun(g,distance1,distance2,mid,k,g[i][j].first,visited);
   	 }
   }

}

int find(vector< pair<int,int> >g[],vector<int>&distance1,vector<int>&distance2,int mid,int k)
{
   vector<int> visited(n+1,0);
   visited[1]=1;	
   int i;

   for(i=0;i<=g[1].size();i++)
   {
   	    if(visited[g[1][i].first]!=1)
        fun(g,distance1,distance2,mid,k,g[1][i].first,visited);
   }
}
int main()
{
	int it,test;
	
	{
		int n,k,temp1,temp2,temp3,temp4,i,j;
		cin>>n>>k;
		vector< vector<int> >a;
		vector< pair<int,int> >g[n+1],g1[n+1];
		for(i=0;i<n-1;i++)
		{
			vector<int> b;
			cin>>temp1>>temp2>>temp3>>temp4;
			b.push_back(temp1);
			b.push_back(temp2);
			b.push_back(temp3);
			b.push_back(temp4);
			a.push_back(b);
			g[temp1].push_back(make_pair(temp2,temp3));
			g1[temp1].push_back(make_pair(temp2,temp4));

		}


		vector<int> visited(n+1,0),distance1(n+1,0),distance2(n+1,0);
		
		dfs(g,g1,visited,1,distance1,distance2);

		for(i=1;i<=n;i++)
		{
			cout<<distance1[i]<<" ";
		}
		cout<<endl;
		for(i=1;i<=n;i++)
		{
			cout<<distance2[i]<<" ";
		}
		cout<<endl;
        
		int hi=0,lo=0;
		for(i=1;i<=n;i++)
		{
           if(hi<distance1[i])
           	hi=distance1;
           if(lo<distance2[i])
           	lo=distance2;
		}

		while(lo<hi)
		{
			mid=lo+(hi-lo)/2;

			if(find(g,distance1,distance2,mid,k))
			{
 
			}

		}
	} 
}