#include<iostream>
#include<string.h>
//#include<stdio.h>
using namespace std;


int maximum(int a ,int b)
{
	if(a>b)return a;
	else
	return b;
}


int lcsdp(char s1[100],char s2[100],int m,int n)
{



 int dp[m+1][n+1];
 int i,j;
 for(i=0;i<=m;i++)
 {
 	for(j=0;j<=n;j++)
 	{
 		if(i==0 || j==0)dp[i][j]=0;
 		
 		else if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
 		
 		else dp[i][j]=maximum(dp[i-1][j],dp[i][j-1]);
	 }
	 
 }
 

 
 
 
  
  int k=dp[m][n]+1;
  char temp[k];
  temp[k-1]='\0';
  k--;
  int arr1[m],arr2[n];
  
  for(i=0;i<m;i++)
   arr1[i]=1;
  
  for(i=0;i<n;i++)
   arr2[i]=1;
  
  i=m,j=n;
  while(1)
  {
  	if(i==0 || j==0) break;
  	
  	else if(s1[i-1]==s2[j-1])
  	{

  		temp[k-1]=s1[i-1];
  		i--,j--,k--;
  		arr2[j]=0;
  		arr1[i]=0;
	  }
	  
	  else if(dp[i-1][j]>dp[i][j-1])
	  {
	  	i--;
	  }
	  else
	  {
	  	j--;
	  }
  }
  
  
//cout<<temp<<endl;
  
  
  
  int count=0;
  i=0,j=0;
  
  while(i<m && j<n)
  {
  	
  	int flag1=i,flag2=j;
  	
  
  	
  	for(;flag1<m && arr1[flag1]==1;flag1++)
  	 cout<<s1[flag1];
  	 
  	for(;flag2<n && arr2[flag2]==1;flag2++)
  	 cout<<s2[flag2];
  	
  	while(flag1<m && flag2<n && arr1[flag1]==0 && arr2[flag2]==0)
  	{
  		cout<<s1[flag1];
  		flag1++;
  		flag2++;
	  }
	  i=flag1,j=flag2;
  	 
  	
  }
  
  while(i<m)
  {
    cout<<s1[i];
  	i++;
  }
  while(j<n)
  {
  	cout<<s2[j];
  	j++;
  }
  
  
  
  cout<<endl;
}



int main()
{
	char s1[1000],s2[1000];
	while(scanf("%s %s",s1,s2)==2)
	{
		
		lcsdp(s1,s2,strlen(s1),strlen(s2));
	}
}
