#include<iostream>
using namespace std;
#include<limits.h>
int less(int a,int b)
{
	if(a<b)return a;
	else
	return b;
}

int rodcut(int a[100],int n)
{
	if(n==0)return 0;
	
	int dp[n+1];
	dp[0]=0;
	
	int i,j;
	
	
	for(i=1;i<=n;i++)
	{
		int m=10001;
		for(j=0;j<i;j++)
		{
			if(a[j]==-1 || dp[i-j-1]==10001)
			continue;
			else
			m=min(m,a[j]+dp[i-j-1]);
			
		}
		dp[i]=m;
	}
	
	for(i=0;i<n+1;i++)
	cout<<dp[i]<<" ";
	cout<<endl;
	if(dp[n]==10001)return -1;
	
	return dp[n];
}


int main()
{
	//int s[100]={-1,-1,3,4,-1};
	
	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		int n,k,i;
		cin>>n>>k;
		
	    int temp[k];
		
		for(i=0;i<k;i++)
		{
			cin>>temp[i];
			//if(temp[i]==-1)
			//temp[i]=10001;
		}
		
		
		cout<<rodcut(temp,k)<<endl;
		
		
	}
	
	
}
