#include<iostream>
#include<vector>
using namespace std;

int main()
{
	long long int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		long long int n,i;
		cin>>n;
		vector < long long int > a(n,0);
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long int count1=n-1,count2=n-1,sum=0;
		for(i=count1;i>=0;i--)
		{   
			
			sum=sum+(count2*a[i]);
			count2=count2-2;
			//cout<<"sum "<<sum<<endl;
		}
		cout<<sum<<endl;
	}
}
