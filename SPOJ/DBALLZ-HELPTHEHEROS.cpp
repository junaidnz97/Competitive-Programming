#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int unboundedknapsack(vector <int> &wt,vector <int> &val,int w,int n)
{
	int i,j;
         
    vector <int> dp(1000000,0);
	for(i=0;i<=w;i++)
	{
		for(j=0;j<n;j++)
		{
            if(i>=wt[j])
			dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
		}
	}

	return dp[w];
}

int main()
{
	int it,test;
	cin>>test;

	for(it=0;it<test;it++)
	{
		int w;
		vector <int> wt(1001,0);
		vector <int> val(1001,0);
		int n,i;

		cin>>w>>n;

		for(i=0;i<n;i++)
		{
			cin>>wt[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>val[i];
		}

		cout<<unboundedknapsack(wt,val,w,n)<<endl;
	}
}