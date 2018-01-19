#include<iostream>
using namespace std;

int main()
{
	
	
	long long int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{ 
	 long long int n;
		cin>>n;
	 long long int k=5,sum=0;
		
		while(n/k > 0)
		{
			sum=sum+n/k;
			k=k*5;
		}
		
		cout<<sum<<endl;
	}
}
