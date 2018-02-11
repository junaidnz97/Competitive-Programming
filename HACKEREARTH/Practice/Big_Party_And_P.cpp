#include<bits/stdc++.h>
using namespace std;


long long int bfs(vector<vector<long long int> >&arr,vector<long long int>&luck,long long int a)
{

	queue <long long int> q;
	q.push(0);
	vector<long long int>visited(a,0);
	visited[0]=1;
	long long int i;
	while(q.size()>0)
	{
		long long int temp=q.front();
		q.pop();
		for(i=0;i<a;i++)
		{
			if(visited[i]==0 && arr[temp][i]==1)
			{
				luck[i]=luck[temp]+1;
				visited[i]=1;
				q.push(i);
			}
		}
	}
	for(i=1;i<a;i++)
	{
		cout<<luck[i]<<endl;
	}

}


int main()
{


	long long int a,b;
	cin>>a>>b;
	vector<vector<long long int> >arr(a,vector<long long int>(a,-1));
	vector<long long int>luck(a,-1);
	luck[0]=0;
	long long int i,j,temp1,temp2;
	for(i=0;i<b;i++)
	{
		cin>>temp1>>temp2;
		arr[temp1][temp2]=1;
		arr[temp2][temp1]=1;
	}
	bfs(arr,luck,a);


}