#include <bits/stdc++.h>
using namespace std;
vector<long long int>a(100001);
vector<long long int>tree(400004);
long long int mod=1000000007;

long long int gcd(long long int a,long long int b)
{
	if(b==0)return a;
	return(gcd(b,a%b));
}

void build(long long int node,long long int start,long long int end)
{
	if(start==end)
	{	
		tree[node]=a[start];
		return ;
	}
	long long int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=gcd(tree[2*node],tree[2*node+1]);
}

long long int query(long long int node,long long int start,long long int end,long long int l,long long int r)
{
	if(start>r || end<l)
		return -1;
	if(start>=l && end<=r)
		return tree[node];
	long long int mid=(start+end)/2;
	long long int temp1=query(2*node,start,mid,l,r);
	long long int temp2=query(2*node+1,mid+1,end,l,r);
	if(temp2==-1 && temp1==-1)
		return 1;
	else if(temp1==-1)
		return temp2;
	else if(temp2==-1)
		return temp1;
	else
		return gcd(temp1,temp2);
}

void multiply(long long int F[2][2], long long int M[2][2])
{
  long long int x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%mod;
  long long int y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%mod;
  long long int z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%mod;
  long long int w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%mod;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(long long int F[2][2], long long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

long long int fib(long long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}

int main()
{
	long long int n,q,i,l,r;
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for(i=1;i<=q;i++)
	{
		cin>>l>>r;
		long long int x=query(1,1,n,l,r);
		cout<<fib(x)<<endl;
	}

}