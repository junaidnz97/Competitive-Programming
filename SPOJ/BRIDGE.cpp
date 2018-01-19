#include<bits/stdc++.h>
using namespace std;

int lis(vector< pair <int,int> > &a,int n)
{
	vector<int> dp(n,0);
	dp[0]=a[0].second;
	int i,j,length=1;
	for(i=1;i<n;i++)
	{
		if(a[i].second<dp[0])
		{
			dp[0]=a[i].second;
		}
		else if(dp[length-1]<a[i].second)
		{
			dp[length++]=a[i].second;
		}
		else
		{
			//dp[bsearch(dp,0,length,a[i])]=a[i];
			dp[upper_bound(dp.begin(),dp.begin()+length,a[i].second)-dp.begin()]=a[i].second;
		}
		/*for(j=0;j<n;j++)
		{
			cout<<dp[j]<<" ";
		}
		cout<<endl;*/
	}
	return length;
}

int main()
{
	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		int n,i;
		cin>>n;
		vector<int>a(n);
		vector<int>b(n);
		for(i=0;i<n;i++)
		{
          cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}

		vector< pair <int,int> > arr;
        
        for(i=0;i<n;i++)
        {
           arr.push_back(make_pair(a[i],b[i]));
        }

        sort(arr.begin(),arr.end());

        /*for(i=0;i<n;i++)
        {
        	cout<<arr[i].first<<" "<<arr[i].second<<endl;
        }*/
        cout<<lis(arr,n)<<endl;

	}
}