#include <bits/stdc++.h>
using namespace std;

vector<int>tree(4000004,0);

void build_tree(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=1;
		return ;
	}
	int mid=(start+end)/2;
	build_tree(2*node,start,mid);
	build_tree(2*node+1,mid+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
}

void update(int node,int start,int end,int i)
{
	if(start==i && end==i)
	{
		tree[node]=0;
		return;
	}
	int mid=(start+end)/2;
	if(i>=start && i<=mid)
		update(2*node,start,mid,i);
	else
		update(2*node+1,mid+1,end,i);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int get_index(int node,int start,int end,int k)
{
	if(tree[node]<k)
		return -1;
	if(start==end && k==1)
		return start;
	int mid=(start+end)/2;
	if(tree[2*node]<k)
		return get_index(2*node+1,mid+1,end,k-tree[2*node]);
	else
		return get_index(2*node,start,mid,k);
}
int main()
{
	int n,q,i,a,b,j;
	cin>>n;
	build_tree(1,1,n);
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>a>>b;
		if(a==0)
			update(1,1,n,b);
		else
			cout<<get_index(1,1,n,b)<<endl;
	}


}