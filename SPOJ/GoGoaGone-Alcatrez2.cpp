#include<iostream>
#include<math.h>
using namespace std;
#include <vector>


int dp[8],dp1[8];

int sum,a[8];
vector <int> b[8];
int ans;

int fun(int n)
{
	
    if(n<=7)
	{
		int i,j;
		//for(i=1;i>=0;i--)
		{
		//	dp[n]=i;
			
			
			if(dp1[n]==1)
			{
				
				for(j=0;j<b[n].size();j++)
				{
					dp1[b[n][j]]=0;
					
				}
				
					fun(n+1);
					
				
					
				
				
			}
			else
			{
			fun(n+1);
			}
			
			
		
		}
		
		
		}
		else
		{
			int k;
			sum=0;
			for(k=0;k<8;k++)
			{
		//	cout<<"test";
		//cout<<dp1[k]<<" ";
			if(dp1[k]==1)
			sum=sum+a[k];
			}
			if(sum>=ans)
			 ans=sum;
			
			
			}
			
			
			
			
			
			
			
			
			
			
			
		
}
			
			
				




int rec(int n)
{
	
	if(n>7)
	{
	int j;
			for(j=0;j<8;j++)
	        dp1[j]=dp[j];
	
	
	fun(0);
	return 0;
	}
	
	int i,j;
	
	for(i=1;i>=0;i--)
	{
		
		dp[n]=i;
		rec(n+1);
			
		
	
	}

	
	
	
	
	
	
	
	
}


int main()
{
	
	int i;
	for(i=0;i<8;i++)
	{
		cin>>a[i];
		dp[i]=0;
	}
	
	int n;
	cin>>n;
	
	int temp1,temp2;
	for(i=0;i<n;i++)
	{
	
	  cin>>temp1>>temp2;
	  
	   b[temp1-1].push_back(temp2-1);
       b[temp2-1].push_back(temp1-1);
	
	}
	
	

ans=0;
rec(0);
//fun(0);
cout<<ans<<endl;
}
