#include<iostream>
#include<limits.h>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;




long long int max(long long int a,long long int b)
{
	if(a>b)return a;
	else return b;
}

/*long long int fun(long long int a[5001],long long int n,long long int i)
{
	if(i>=n-1)
	{ 
	   
	  return 1;
    }
	
	int k;
	int x=INT_MIN;
	k=i;

	
	x=INT_MIN;
	
	if((a[k]>0 && a[k+1]<0 && a[k]< -a[k+1])||(a[k]<0 && a[k+1]>0&& -a[k]<a[k+1]))
	{
	
	      return 1+fun(a,n,k+1);
    
	}
	else
	{
		
		return fun(a,n,k+2);
	}	
    
	
    
}*/

long long int fun(long long int a[5001],long long int n)
{
	
	vector <long long int> dp(5001,0);
	
	dp[n-1]=1;
	long long int i,j;
	for(i=n-2;i>=0;i--)
	{
		long long int x=INT_MIN;
		
		for(j=i;j<n;j++)
		{
			if((a[i]>0 && a[j]<0 && a[i]< -a[j])||(a[i]<0 && a[j]>0&& -a[i]<a[j]))
			{
				x=max(x,1+dp[j]);
			}
		}
		if(x<0)x=1;
		dp[i]=x;
	}
	
	long long int flag=INT_MIN;
	for(i=0;i<n;i++)
	{
	//	cout<<dp[i]<<" ";
		flag=max(flag,dp[i]);
	}
	
	return flag;
}

int main()
{
	
	long long int n,a[5001];
    cin>>n;
    
    long long int i,j;
    
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	
  
   
   cout<<fun(a,n)<<endl;
}
