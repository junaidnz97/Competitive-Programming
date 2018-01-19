#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int maximum(int a,int b)
{
	if(a>b)return a;
	else
	return b;
}

int lcs(char x[6101],char y[6101])
{
	 
	 
	 int m=strlen(x);
	 int n=m;
     int i,j;
     
         vector< vector<int> > dp(6101, vector<int> (6101));

     for(i=0;i<=m;i++)
     {
 	   for(j=0;j<=n;j++)
 	   {
 		if(i==0 || j==0)dp[i][j]=0;
 		
 		else if(x[i-1]==y[j-1])dp[i][j]=1+dp[i-1][j-1];
 		
 		else dp[i][j]=maximum(dp[i-1][j],dp[i][j-1]);
	   }
	 
     }
     return dp[m][n];
}

int main()
{

  long long int it,test;
  
  cin>>test;
  
  for(it=0;it<test;it++)
  {
  	
  	char c[6101],rev[6101];
  	
  	cin>>c;
  		
    int i,j;
    int l=strlen(c);
    j=0;
    
    for(i=l-1;i>=0;i--)
    {
      rev[j++]=c[i];	
	}
  	//cout<<rev<<endl;
  	
  	cout<<strlen(c)-lcs(c,rev)<<endl;
  	
  	
	  }	
}
