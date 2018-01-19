#include<stdio.h>
#include<math.h>
#include <string.h>
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

float fun(long long int n,long long int k)
{
	long long int i,j;
	
vector< vector<float> > dp(546, vector<float> (1909,0.0));

	//cout<<"hello";
	for(j=1;j<=6;j++)
	{   //cout<<"test1";
		dp[1][j]=(1/6.0);
	}
	
		/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(j-1>=0)
			{
				dp[i][j]+=dp[i-1][j-1];
			}
			if(j-2>=0)
			{
				dp[i][j]+=dp[i-1][j-2];
			}
			if(j-3>=0)
			{
				dp[i][j]+=dp[i-1][j-3];
			}
			if(j-4>=0)
			{
				dp[i][j]+=dp[i-1][j-4];
			}
			if(j-5>=0)
			{
				dp[i][j]+=dp[i-1][j-5];
			}
			if(j-6>=0)
			{
				dp[i][j]+=dp[i-1][j-6];
			}
			dp[i][j]=dp[i][j]/6;
		}
	}
	/*
		for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			 cout<< dp[i][j]<<"\t\t";
		}
		cout<<endl;
	}*/
	return dp[n][k];
}

int main()
{
	
	int it,test;
	cin>>test;

	for(it=0;it<test;it++)
	{
		long long int n,k;
		cin>>n>>k;
		
		if(n>=545 || k>=1908) cout<<"0"<<endl;
		else
		{
		
        double temp=fun(n,k)*100;
        
		cout<<(long long int)temp<<endl;
	    }
 	}
}
