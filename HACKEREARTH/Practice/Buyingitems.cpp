#include<bits/stdc++.h>
using namespace std;

long long int fun(vector<long long int>&a,vector<long long int>&cost,long long int m,long long int n)
{
	vector<long long int>currentcost(1<<n,-1);
	vector<long long int>qpresent(1<<n,0);

	currentcost[0]=0;
	queue<long long int>q;
	q.push(0);
	long long int i,j;
	while(q.size()>0)
	{
		long long int temp=q.front();
		q.pop();
		qpresent[temp]=0;
		for(j=0;j<m;j++)
		{
			long long int x=temp|a[j];
			//cout<<x<<endl;
			if(currentcost[x]==-1)
			{
				currentcost[x]=currentcost[temp]+cost[j];
				q.push(x);
				qpresent[x]=1;
			}
			else
			{
				currentcost[x]=min(currentcost[x],currentcost[temp]+cost[j]);
				if(currentcost[x]>currentcost[temp]+cost[j] && qpresent[x]==0)
					q.push(x);
			}
		}

	}
	return currentcost[(1<<n)-1];
}

vector<long long int> superimpose(vector<long long int>&a,vector<long long int>&b,int n)
{
	long long int i;
	vector<long long int>c=a;
	for(i=0;i<n;i++)
	{
		if(b[i]==1)
			c[i]=1;
	}
	return c;

}
int check(vector<long long int>&a,int n)
{
	for(int i=0;i<n;i++)
		if(a[i]==0)
			return 0;
	return 1;
}

long long int fun2(vector<vector<long long int> >&a,vector<long long int>&cost,long long int m,long long int n)
{
	long long int i,j;
	unsigned long long int fincost=ULLONG_MAX;
	//cout<<fincost<<endl;
	for(i=0;i<1<<m;i++)
	{	
		vector<long long int>init(n,0);
		vector<long long int>tempvec;
		unsigned long long int tempcost=0;
		tempvec=init;
		for(j=0;j<m;j++)
		{
			if((i>>j)&1)
			{
				tempvec=superimpose(tempvec,a[j],n);
				tempcost=tempcost+cost[j];
			}
		}
		if(check(tempvec,n))
		{
			fincost=min(fincost,tempcost);
			//cout<<tempcost<<endl;		
		}
	}
	return fincost;
}

int main()
{
	long long int n,m;
	cin>>n>>m;
	vector<vector<long long int> >a(m,vector<long long int>(n,0));
	vector<long long int>cost(m,0);
	long long int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
		cin>>cost[i];
	}

/*	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	vector<long long int>b;
	for(i=0;i<m;i++)
	{
		long long int count=0;
		for(j=0;j<n;j++)
		{	
			//cout<<pow(2,n-j-1)*a[i][j]<<endl;
			count+=pow(2,n-j-1)*a[i][j];
		}
		b.push_back(count);
	}
	
	if(n<=22)
	cout<<fun(b,cost,m,n)<<endl;
	else
	cout<<fun2(a,cost,m,n)<<endl;
	
	
}