#include<bits/stdc++.h>
using namespace std;


int main()
{
	int m,p;
	cin>>m>>p;

	int i;
	int sum=0;
	vector<int>a(p,0);
	for(i=0;i<p;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}

	int low=0,high=sum;
	int mid;
	while(low<high)
	{

		mid=(low+high)/2;

		int count=1,temp=0;
		for(i=0;i<p;i++)
		{
			if(a[i]>mid)
			{
				count=m+1;
				break;
			}
			if(temp+a[i]<=mid)
			{
				temp+=a[i];
			}
			else
			{
				//cout<<"hello"<<endl;

				temp=a[i];
				count++;
			}
			//cout<<temp<<endl;
		}
		//cout<<mid<<" "<<count<<endl;
		if(count>m)
		{
			low=mid+1;
		}
		else
		{
			high=mid;
		}
	}
	cout<<low<<endl;


}