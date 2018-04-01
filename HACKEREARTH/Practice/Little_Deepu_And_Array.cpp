#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n;
	cin>>n;
	int i;
	vector<int>a(n+1,0);
	for(i=0;i<n;i++)
		cin>>a[i];
	int m,j;
	cin>>m;
	for(j=0;j<m;j++)
	{
		int temp;
		cin>>temp;
		for(i=0;i<n;i++)
		{
			if(a[i]>temp)
				a[i]=a[i]-1;
		}
	}

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

}