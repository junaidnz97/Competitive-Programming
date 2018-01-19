#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

inline long long int bsearch(vector <pair<long long int,long long int> >& a,long long int low,long long int high,long long int p)
{
      
	  while(low<high)
	  {
	  	//cout<<"est1";
	  	long long int mid=(low+high)/2;
	  	 
	  	if(a[mid].first>=p)
	  	high=mid;
	  	
	  	else low=mid+1;
	  	
	   }	
	 if(a[low].first<p)return -1;
	 
	 else return low;
	
}

int main()
{
	ios::sync_with_stdio(false);
	
	while(1)
	{
		long long int n,i,j;
		cin>>n;

		if(n==-1)
			return 0;
		
		vector<pair<long long int,long long int> > a(n);

		for(i=0;i<n;i++)
		{
			cin>>a[i].first;
			cin>>a[i].second;

		}
		/*for(i=0;i<n;i++)
		{
			cout<<a[i].first;
			cout<<a[i].second;
		}*/
        sort(a.begin(),a.end());

      /* for(i=0;i<n;i++)
		{
			cout<<a[i].first<<" ";
			cout<<a[i].second<<endl;
		}*/


       long long int dp[100001];
       dp[n-1]=1;
       long long int t;
       for(i=n-2;i>=0;i--)
       {
       	
       	   t=bsearch(a,i,n,a[i].second);
       	  
       	   dp[i]=(dp[i+1]+1)%100000000;
       	   
		   if(t!=-1)
       	   {
       	   	dp[i]=(dp[i]+dp[t])%100000000;
			  }
	   }
	   
	   //for(i=0;i<n;i++)
	   //{
	    //   cout<<dp[i]<<" ";
	   //}
	   
	  
	  
	  long long int x=dp[0];
	  
	  long long int count=0;
	  
	  while(x>0)
	  {
	  	x=x/10;
	  	count++;
	  }
	  
	  if(count<=8)
	  {
	  	for(i=0;i<8-count;i++)
	  	cout<<"0";
	  }
	  cout<<dp[0]<<'\n';
	}
}
