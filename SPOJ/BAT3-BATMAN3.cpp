#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

int  dypro(vector <int> &a,int n,int flag)
{

	vector <int> dp(n,1);
    
    int i,j,maxi,temp;

	for(i=n-2;i>=0;i--)
	{
         maxi=INT_MIN;
         temp=a[i];

         for(j=i+1;j<n;j++)
         {

             
         	
          if(temp>a[j] || flag==i)
         	{
         		maxi=max(maxi,1+dp[j]);
         	}

         	


         }
         if(maxi>=0)
         dp[i]=maxi;
	}

    int ans=dp[0];
	for(i=0;i<n;i++)
	{
		//cout<<dp[i]<<" ";
      if(dp[i]>ans)
      	ans=dp[i];

	}
	//cout<<endl;
	cout<<ans<<endl;
	return 0;
}

int main()
{

   int it,test;
   cin>>test;

   for(it=0;it<test;it++)
   {

   	  int n,flag;
   	  cin>>n>>flag;

   	  vector<int> a(n);

   	  int i;
   	  for(i=0;i<n;i++)
   	  {
   	  	cin>>a[i];
   	  }

   	  dypro(a,n,flag);
   }
}