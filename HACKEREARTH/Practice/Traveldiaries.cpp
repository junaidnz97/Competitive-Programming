#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long int i,j;
	long long int time;
};

int check(vector<vector<long long int> >&a,int m,int n)
{
	int i,j;
	for (int i = 1; i < m+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			if(a[i][j]==1)
				return 1;
		}
	}
	return 0;
}
int print(vector<vector<long long int> >&a,int m,int n)
{
	int i,j;
	cout<<"\n\n\n\n\n";
	for (int i = 1; i < m+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
int main()
{
	long long int n,m;
	cin>>m>>n;

	long long int i,j;
	queue<node> q;
	vector<vector<long long int> >a(m+2,vector<long long int>(n+2,-1));
	vector<vector<long long int> >b(m+2,vector<long long int>(n+2,-1));
	long long int maxtime=0;
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==2)
			{
				node temp;
				temp.i=i;
				temp.j=j;
				temp.time=0;
				q.push(temp);
				b[i][j]=1;
			}
			//cout<<i<<" "<<j<<endl;
		}
	}
	/*for(i=0;i<m+2;i++)
	{
		for(j=0;j<n+2;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	while(q.size()>0)
	{
		node temp=q.front();
		q.pop();
		//cout<<temp.i<<" "<<temp.j<<endl;	
		if(a[temp.i-1][temp.j]==1)
		{
			//cout<<"a"<<endl;
			a[temp.i-1][temp.j]=2;
			node x;
			x.i=temp.i-1;
			x.j=temp.j;
			x.time=temp.time+1;
			maxtime=max(maxtime,temp.time+1);
			q.push(x);
			//cout<<x.i<<" "<<x.j<<endl;
		}
		if(a[temp.i][temp.j-1]==1)
		{
			//cout<<"b"<<endl;
			a[temp.i][temp.j-1]=2;
			node x;
			x.i=temp.i;
			x.j=temp.j-1;
			x.time=temp.time+1;
			maxtime=max(maxtime,temp.time+1);
			q.push(x);
			//cout<<x.i<<" "<<x.j<<endl;
		}
		if(a[temp.i+1][temp.j]==1)
		{
			//cout<<"c"<<endl;
			a[temp.i+1][temp.j]=2;
			node x;
			x.i=temp.i+1;
			x.j=temp.j;
			x.time=temp.time+1;
			maxtime=max(maxtime,temp.time+1);
			q.push(x);
			//cout<<x.i<<" "<<x.j<<endl;
		}
		if(a[temp.i][temp.j+1]==1)
		{
			//cout<<"d"<<endl;
			a[temp.i][temp.j+1]=2;
			node x;
			x.i=temp.i;
			x.j=temp.j+1;
			x.time=temp.time+1;
			maxtime=max(maxtime,temp.time+1);
			q.push(x);
			//cout<<x.i<<" "<<x.j<<endl;
		}

	}

	//print(a,m,n);

	if(check(a,m,n))
		cout<<"-1"<<endl;
	else
	cout<<maxtime<<endl;

}