#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int dp[10000][101];
int num;
int l;
int t;
char n[10000];

int fun(int low,int k,char temp[10000])
{
	
	if(low == t)
	{
		if(k>num)return 1;
		
		else return 0;
	}
	
	if(dp[k][low]!=-1)return dp[k][low];
	
	int i;
	if(low%2==0)
	{
	
	for(i=0;i<l;i++)
	{
		char n1[10000];
		
		strcpy(n1,temp);
		
		if(n1[i]=='9') n1[i]='0';
		
		else n1[i]=n1[i]+1;
		
		if(i==0)dp[k][low]=0||fun(low+1,atoi(n1),n1);
		
		else dp[k][low]=dp[k][low]||fun(low+1,atoi(n1),n1);
		
		
	}
    }
    else
    {
    	
    	
    	for(i=0;i<l;i++)
	{
		char n1[10000];
		
		strcpy(n1,temp);
		
		if(n1[i]=='9') n1[i]='0';
		
		else n1[i]=n1[i]+1;
		
		if(i==0)dp[k][low]=1&&fun(low+1,atoi(n1),n1);
		
		else dp[k][low]=dp[k][low]&&fun(low+1,atoi(n1),n1);
		
		
	}
    	
	}
	//cout<<dp[k][low]<<endl;
	return dp[k][low];
}

int main()
{
	
	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		cin>>n>>t;
		
		memset(dp, -1, sizeof(dp) );
		
		num=atoi(n);
		char temp[10000];
		strcpy(temp,n);
		l=strlen(n);
		int flag=fun(0,num,temp);
	
        if(flag==0)cout<<"Vinit"<<endl;
        else cout<<"Ada"<<endl;
        
	}
}
