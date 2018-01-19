#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	
	
	long long int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		long double n,k,m;
		
		cin>>n>>k>>m;
		
		
		long long int t=0;
		
		if(n<m)
		{
		
		while(1)
		{
			n=n*k;
			if(n<=m)t++;
			else break;
		}
		
		cout<<t<<endl;
	}
	else
	{
		cout<<"0"<<endl;
	}
	
	}
}
