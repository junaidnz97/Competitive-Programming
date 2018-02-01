#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long int i,j;
};

long long int find(vector<vector<long long int> >&a,long long int m,long long int n,long long int r,long long int s)
{
	//cout<<"sdiuhhu";
	queue <node> q;
	vector<vector<long long int> >b(m+2,vector<long long int>(n+2,0));
	vector<vector<long long int> >time(m+2,vector<long long int>(n+2,INT_MAX));

	node init;
	init.i=1;
	init.j=1;
	time[1][1]=a[1][1];
	q.push(init);
	b[1][1]=1;
	//cout<<"hello";
	while(q.size()>0)
	{
		node temp=q.front();
		q.pop();
		b[temp.i][temp.j]=0;


		if(b[temp.i-1][temp.j]==0)
		{
			if(a[temp.i-1][temp.j]>0)
			{
				
				node add;
				add.i=temp.i-1;
				add.j=temp.j;
				if(time[temp.i-1][temp.j]>time[temp.i][temp.j]+a[temp.i-1][temp.j])
				{
					b[temp.i-1][temp.j]=1;
					time[temp.i-1][temp.j]=time[temp.i][temp.j]+a[temp.i-1][temp.j];
					q.push(add);
				}		
			}
		}
		else
		{
			time[temp.i-1][temp.j]=min(time[temp.i-1][temp.j],time[temp.i][temp.j]+a[temp.i-1][temp.j]);	
		}


		if(b[temp.i][temp.j-1]==0)
		{
			if(a[temp.i][temp.j-1]>0)
			{
				
				node add;
				add.i=temp.i;
				add.j=temp.j-1;
				if(time[temp.i][temp.j-1]>time[temp.i][temp.j]+a[temp.i][temp.j-1])
				{	
					b[temp.i][temp.j-1]=1;
					time[temp.i][temp.j-1]=time[temp.i][temp.j]+a[temp.i][temp.j-1];
					q.push(add);
				}		
			}
		}
		else
		{
			time[temp.i][temp.j-1]=min(time[temp.i][temp.j-1],time[temp.i][temp.j]+a[temp.i][temp.j-1]);	
		}

		if(b[temp.i+1][temp.j]==0)
		{
			if(a[temp.i+1][temp.j]>0)
			{
				
				node add;
				add.i=temp.i+1;
				add.j=temp.j;
				if(time[temp.i+1][temp.j]>time[temp.i][temp.j]+a[temp.i+1][temp.j])
				{	
					b[temp.i+1][temp.j]=1;
					time[temp.i+1][temp.j]=time[temp.i][temp.j]+a[temp.i+1][temp.j];
					q.push(add);
				}		
			}
		}
		else
		{
			time[temp.i+1][temp.j]=min(time[temp.i+1][temp.j],time[temp.i][temp.j]+a[temp.i+1][temp.j]);	
		}

		if(b[temp.i][temp.j+1]==0)
		{
			if(a[temp.i][temp.j+1]>0)
			{
				
				node add;
				add.i=temp.i;
				add.j=temp.j+1;
				if(time[temp.i][temp.j+1]>time[temp.i][temp.j]+a[temp.i][temp.j+1])
				{
					b[temp.i][temp.j+1]=1;
					time[temp.i][temp.j+1]=time[temp.i][temp.j]+a[temp.i][temp.j+1];
					q.push(add);
				}		
			}
		}
		else
		{
			time[temp.i][temp.j+1]=min(time[temp.i][temp.j+1],time[temp.i][temp.j]+a[temp.i][temp.j+1]);	
		}


		
	}

	//cout<<time[r][s]<<endl;
	
	/*long long int i,j;
	for(i=0;i<m+1;i++)
	{
		for(j=0;j<n+1;j++)
			cout<<time[i][j]<<" ";
		cout<<endl;
	}*/
	return(time[r][s]);

}

int main()
{
	long long int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		long long int m,n;
		cin>>m>>n;
		vector<vector<long long int> >a(m+2,vector<long long int>(n+2,-1));
		long long int i,j;

		for(i=1;i<m+1;i++)
		{
			for(j=1;j<n+1;j++)
			{
				//cout<<i<<" "<<j<<endl;
					cin>>a[i][j];
			}
		}
		//cout<<"hello";
		long long int r,s,t;
		cin>>r>>s>>t;
		//r=1,s=3,t=76;
		
		long long int time=find(a,m,n,r,s);;
		if(time<=t)
		{
			cout<<"YES"<<endl<<t-time<<endl;
		}
		else
			cout<<"NO"<<endl;
	}

	
}