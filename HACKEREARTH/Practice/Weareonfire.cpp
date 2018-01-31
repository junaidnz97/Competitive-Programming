#include<bits/stdc++.h>
using namespace std;

long long int counter=0;
int find(vector<vector<long long int> >&a,long long int m,long long int n,long long int i,long long int j)
{
	if(a[i][j]==1)
	{
		counter--;
		
		a[i][j]=2;
		if(a[i+1][j]==1)
		{
			find(a,m,n,i+1,j);
		}
		if(a[i][j+1]==1)
		{
			find(a,m,n,i,j+1);
		}
		if(a[i-1][j]==1)
		{
			find(a,m,n,i-1,j);
		}
		if(a[i][j-1]==1)
		{
			find(a,m,n,i,j-1);
		}
	}

}
int main()
{
	long long int n,m,q,i,j;
	//cin>>m>>n>>q;
	scanf("%lld",&m);
	scanf("%lld",&n);
	scanf("%lld",&q);
	counter=0;
	vector<vector<long long int> >a(m+2,vector<long long int>(n+2,-1));
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]==1)
				counter++;
		}
	}
	while(q--)
	{

		scanf("%lld",&i);
		scanf("%lld",&j);
		
		//cout<<a[i][j]<<" "<<i<<" "<<j<<endl;
		if(a[i][j]==1)
			find(a,m,n,i,j);
		printf("%lld\n", counter);
	}

}