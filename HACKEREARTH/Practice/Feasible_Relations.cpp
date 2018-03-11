#include<bits/stdc++.h>
using namespace std;


int dfs(vector<vector<int> >&gg,vector<int>&visited,int i,int set_no,vector<int>&finset)
{

	if(visited[i]==0)
	{
		visited[i]=1;
		int j;
		finset[i]=set_no;
		for(j=0;j<gg[i].size();j++)
		{
			if(visited[gg[i][j]]==0)
			{
				dfs(gg,visited,gg[i][j],set_no,finset);
			}
		}
	}
}

int main()
{


	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		int n,k;
		cin>>n>>k;
		vector<vector<int> >gg(n+1),bg(k,vector<int>(2,-1));
		int i;

		for(i=0;i<k;i++)
		{
			int temp1 ,temp2;
			string str;
			cin>>temp1>>str>>temp2;
			if(str=="=")
			{
				gg[temp1].push_back(temp2);
				gg[temp2].push_back(temp1);
			}
			else
			{
				bg[i][0]=temp1;
				bg[i][1]=temp2;
			}
		}

		int set_no=1;
		vector<int>visited(n+1,0),finset(n+1,-1);
		for(i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				dfs(gg,visited,i,set_no,finset);
				set_no++;
			}
		}
		int flag=1;


		for(i=0;i<k;i++)
		{
			if((finset[bg[i][0]]==finset[bg[i][1]])&&(finset[bg[i][0]]!=-1 && bg[i][1]!=-1))
			{	
				flag=0;
				cout<<"NO"<<endl;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"YES"<<endl;
		}
	}
}