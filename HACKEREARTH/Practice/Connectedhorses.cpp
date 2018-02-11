#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long int jumps[9][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

vector<long long int>fac(1000001,1);

long long int factorial()
{
	long long int i;
	for(i=1;i<1000001;i++)
		fac[i]=(i*fac[i-1])%mod;
}
long long int sum;

long long int dfs(vector<vector<long long int> >&chessboard,long long int m,long long int n,long long int i,long long int j,vector<vector<long long int> >&visited)
{

	if(visited[i][j]==0 && chessboard[i][j]==1) 
	{
		
		visited[i][j]=1;
		sum++;
		long long int p,q;
		for(p=0;p<8;p++)
		{
			long long int tempi=i+jumps[p][0];
			long long int tempj=j+jumps[p][1];
			if((tempi<1 || tempi >m) || (tempj<1 || tempj>n ) )
				continue;
			else if (visited[tempi][tempj]==0 && chessboard[tempi][tempj]==1)
			{	
				//cout<<tempi<<" "<<tempj<<endl;
				dfs(chessboard,m,n,tempi,tempj,visited);
				
			}	
			else
				continue;
		}	
	}

}

int main()
{
	long long int it,test;
	cin>>test;
	factorial();
	for(it=0;it<test;it++)
	{
		long long int m,n;
		cin>>m>>n;
		vector<vector<long long int> > chessboard(m+1,vector<long long int>(n+1,0));
		vector<vector<long long int> >visited(m+1,vector<long long int>(n+1,0));
		long long int q,i,j;
		cin>>q;

		vector<long long int>xcord(q,0);
		vector<long long int>ycord(q,0);
		for(i=0;i<q;i++)
		{
			cin>>xcord[i]>>ycord[i];
			chessboard[xcord[i]][ycord[i]]=1;
		}

		/*for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				cout<<chessboard[i][j]<<" ";
			}
			cout<<endl;
		}*/
		
		long long int finans=1;
		
		
		
		for(i=1;i<m+1;i++)
		{
			for(j=1;j<n+1;j++)
			{
				
				sum=0;
				if(visited[i][j]==0 && chessboard[i][j]==1)
				{
					dfs(chessboard,m,n,i,j,visited);
					
				}
				//cout<<sum<<endl;
				finans=(finans*fac[sum])%mod;
			}
		}
		cout<<finans<<endl;
	}
}