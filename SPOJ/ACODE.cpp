#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;


int acode(char s[5000])
{
	
	int n=strlen(s);
	
	int i;
	int dp[n+1];
	dp[0]=1;
	dp[1]=1;
	for(i=1;i<=n-1;i++)
	{
		int t1=s[i-1]-'0',t2=s[i]-'0';
		t1=t1*10+t2;
		
		if(t1<=26) 
		{
		if(t1>=10)	
		
		{
		if(t1%10!=0)
		dp[i+1]=dp[i-1]+dp[i];
		else
		{	
			dp[i+1]=dp[i-1];
		}
	}
		else
		{
			if(t1==0)return 0;
			else
			{
				dp[i+1]=dp[i];
			}
		}
		
		}
		else
		{
		
		if(t1%10!=0)
		{
		dp[i+1]=dp[i];
		
		
		
		}
		else
		return 0;
		
	}
				
	}
	
	
//	cout<<dp[n];

//for(i=0;i<=n;i++)
// cout<<dp[i]<<" ";
	return dp[n];
	
}



int main()
{
	
	
	while(1)
	{
		char str[5000];
		cin>>str;
		
		if(strcmp("0",str)==0)
		break;
		
     	//cout<<acode(str);
		cout<<acode(str)<<endl;
//acode(str);
	}
}
