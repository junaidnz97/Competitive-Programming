#include<bits/stdc++.h>
using namespace std;

int findmin(vector<int>&a,int m)
{
   int i,mini=INT_MAX;
   for(i=0;i<m;i++)
   {
      mini=min(mini,a[i]);
   }
   return mini;
}

int findsum(vector<int>&a,int m)
{

	int sum=0,i;
	for(i=0;i<m;i++)
	{
		sum=sum+a[i];
	}
	return sum;
}

int satisfy(vector<int>&a,int m,int maxi,int k)
{
   int count=1,i;
   int work=a[0];

   for(i=1;i<m;i++)
   {
   	  if(work+a[i]<=maxi)
   	  {
   	  	work=work+a[i];
   	  }
   	  else
   	  {
   	  	count++;
   	  	work=a[i];
   	  }
   	

   }

     if(count<=k)
   	  	return 1;
   return 0;
}

int binarysearch(vector<int>&a,int m,int k)
{
	//cout<<"hello"<<endl;
	int low=findmin(a,m);
	int high=findsum(a,m);
	int mid=(low+high)/2;
    int maxi=INT_MAX;
    //cout<<endl;
    //cout<<"hello1"<<endl;
	while(low<=high)
  	{  // cout<<"hello2"<<endl;
		mid=(low+high)/2;
		int x=satisfy(a,m,mid,k);
		if(x==0)
		{   
			//cout<<"unsatisfied "<<mid<<endl; 
			low=mid+1;
			//maxi=max(maxi,low);
		}
		else
		{
			//cout<<"satisfied"<<mid<<endl;
			maxi=min(maxi,mid);
            high=mid-1;
		}
	}
	return maxi;
}

int main()
{
    int it,test;
    cin>>test;
    for(it=0;it<test;it++)
    {
    	int m,k;
    	int i,temp;
    	cin>>m>>k;
    	vector<int>a;
    	//cout<<m<<k<<endl;
    	for(i=0;i<m;i++)
    	{
    		cin>>temp;
    		a.push_back(temp);

    	}
    	//cout<<"test2";
        
    	int x=binarysearch(a,m,k);
    	vector<int>dp(m,0);
    	int sum=0;

    	cout<<x<<endl;

    	for(i=m-1;i>=0;i--)
    	{
            if(sum+a[i]<x)
            	sum=sum+a[i];
            else
            {
            	sum=0;
            	dp[i]=1;
            }
        }

        for(i=0;i<m;i++)
        {
        	if(dp[i]==1)
        		cout<<"\\"<<" ";
        	
        		cout<<a[i]<<" ";

        }
        
        cout<<endl;
    	}

    }
