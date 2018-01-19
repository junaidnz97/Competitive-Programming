#include<iostream>
#include<vector>
using namespace std;

long long int max(long long int a,long long int b)
{
	if(a>b)return a;
	else return b;
}

long long int dypro(vector <long long int> &a,long long int n)

{
	    if(n==1)
	    	return a[0];
	    else if(n==0)
	    	return 0;
	    long long int i;

        vector <long long int> dp(n+1);
	    dp[0]=0;
        dp[1]=a[0];
        dp[2]=max(a[0],a[1]);
		for(i=3;i<=n;i++)
		{
          
           dp[i]=max(dp[i-2]+a[i-1],dp[i-1]);
		}

		/*for(i=0;i<=n;i++)
		{
			cout<<dp[i]<<" ";
		}

        cout<<endl;*/
		return max(dp[n],dp[n-1]);
}

int main()
{
	long long int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		long long int n;
		cin>>n;
		vector <long long int> a(n);
		long long int i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}

        cout<<"Case "<<it+1<<": "<<dypro(a,n)<<endl;

    }
}