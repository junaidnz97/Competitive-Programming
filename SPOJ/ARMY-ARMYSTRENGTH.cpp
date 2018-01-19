#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main()
{
	int it,test;
	cin>>test;

	for(it=0;it<test;it++)
	{
		int ng,nm;
		cin>>ng>>nm;

		vector <int> a(ng);
		vector <int> b(nm);

		int i;
		int maxi=0,maxj=0;
		for(i=0;i<ng;i++)
		{
           cin>>a[i];
           if(a[i]>maxi)maxi=a[i];
		}
        int j;
		for(j=0;j<nm;j++)
		{
			cin>>b[j];
			if(b[j]>maxj)maxj=b[j];
		}

		if(maxi>=maxj)
			cout<<"Godzilla"<<endl;
		else
			cout<<"MechaGodzilla"<<endl;
	}
}