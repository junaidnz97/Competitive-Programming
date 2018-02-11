#include<bits/stdc++.h>
using namespace std;
#define RANGE 50005



int main()
{

	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		int n;
		cin>>n;
		int i;
		int a[100001];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		int count=0,num=0,c=0,flag=0;
		for(i=0;i<n;i++)
		{
			if(a[i]-count<=0)
			{
				flag=1;
				break;
			}
			else
			{
				count++;
				c++;
				num++;
				if(c%6==0 && c!=0)
				{
					c=0;
					count++;
				}
			}
		}
		if(flag==0)
		{
			cout<<"Rick now go and save Carl and Judas"<<endl;
		}
		else
		{
			cout<<"Goodbye Rick"<<endl;
			cout<<num<<endl;
		}

	}
}