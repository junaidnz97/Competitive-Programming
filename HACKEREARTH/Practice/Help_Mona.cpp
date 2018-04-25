#include<bits/stdc++.h>
using namespace std;

vector<int>a(2000001,0),tree(8000004,0);

int buildtree(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=a[start];
		return 0;
	}
	int mid=(start+end)/2;
	buildtree(2*node,start,mid);
	buildtree(2*node+1,mid+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int update(int node,int start,int end,int pos)
{
	if(start>pos || end<pos)
		return 0;
	if(start==end )
	{
		tree[node]=(tree[node]+1)%2;
		return 0;
	}
	int mid=(start+end)/2;
	update(2*node,start,mid,pos);
	update(2*node+1,mid+1,end,pos);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int start,int end,int k)
{

	//cout<<"hello";
	if(start==end)
	{
		return start;
	}

	int mid=(start+end)/2;
	
	if(k<=tree[2*node])
	{	//cout<<"h1"<<endl;
		return query(2*node,start,mid,k);
	
	}
	else 	
	{	//cout<<"h2"<<endl;
		return query(2*node+1,mid+1,end,k-tree[2*node]);
	}
}

int main()
{
	int n,i,q,j;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{	
		cin>>a[i];
		a[i]=a[i]%2;
	}
	buildtree(1,1,n);
	
	for(i=1;i<=q;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		if(temp1==1)
		{
			update(1,1,n,temp2);
		}
		else
		{
			if(tree[1]<temp2)
				cout<<"-1"<<endl;
			else
			cout<<query(1,1,n,temp2)<<endl;
		}
		

	}	
}