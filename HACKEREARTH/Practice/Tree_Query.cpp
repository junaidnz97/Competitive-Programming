#include<bits/stdc++.h>
using  namespace std;

int main()
{

	int n,m;
	cin>>n>>m;
	int i;
	vector<vector<int> >g1(n+1),g2(n+1);
	for(i=0;i<m;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		g1[temp1].push_back(temp2);
		g2[temp2].push_back(temp1);
	}

	int count1=0,count2=0;
	for(i=1;i<=n;i++)
	{
		if(g1[i].size()==0)
			count1++;
		if(g2[i].size()==0)
			count2++;

	}

	cout<<max(count1,count2)<<endl;

}