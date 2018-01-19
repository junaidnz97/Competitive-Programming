#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int m,n,i;
	cin>>m;
	vector<long long int> a(m);
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	cin>>n;
	vector<long long int> b(n);
	long long int maxi=INT_MIN;
	for(i=0;i<n;i++)
	{
		cin>>b[i];
		maxi=max(maxi,b[i]);
	}
	long long int ans=0;
	for(i=0;i<m;i++)
	{
		if(a[i]<=maxi)
		{
			ans+=maxi-a[i]+1;
		}
	}
	cout<<ans<<endl;

}