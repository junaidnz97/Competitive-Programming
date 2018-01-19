#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int it,test;
	cin>>test;

	for(it=1;it<=test;it++)
	{
		int s,n,i,a[10000];
		cin>>s>>n;



		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}

		sort(a,a+n);

		/*for(i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}*/
        int sum=0,count=0;
		for(i=n-1;i>=0;i--)
		{
			sum=sum+a[i];
			count++;
			if(sum>=s)break;
		}

        
		cout<<"Scenario #"<<it<<":"<<endl;

		if (sum<s)
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			cout<<count<<endl;
		}

		cout<<endl;
 


	}
}