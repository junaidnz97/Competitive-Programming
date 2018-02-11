#include<bits/stdc++.h>
using namespace std;

struct node
{
	int n;
	int count;
};

int bfs(int n)
{

	queue <node> q;
	set <int>s;
	node x;
	x.n=n;
	x.count=0;
	s.insert(n);
	q.push(x);

	
	while(q.size()>0)
	{
		if(q.front().n==1)
			return q.front().count;

		node temp=q.front();
		
		q.pop();

		if((temp.n)%3==0)
		{
			node flag;
			flag.n=temp.n/3;
			flag.count=temp.count+1;
			if((*(s.find(flag.n))-*(s.end()))==0)
			{
				q.push(flag);
				s.insert(flag.n);
			}
			if(flag.n==1)
				return(flag.count);
		}

		if((temp.n)%2==0)
		{
			
			node flag;
			flag.n=temp.n/2;
			flag.count=temp.count+1;
			
			if((*(s.find(flag.n))-*(s.end()))==0)
			{
				
				q.push(flag);
				s.insert(flag.n);
			}
			if(flag.n==1)
				return(flag.count);
			
		}
		
		node flag;
		flag.n=temp.n-1;
		flag.count=temp.count+1;
		if((*(s.find(flag.n))-*(s.end()))==0)
		{
			q.push(flag);
			s.insert(flag.n);
		}
		if(flag.n==1)
			return(flag.count);
	}



}

int main()
{
	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		int n;
		cin>>n;
		cout<<bfs(n)<<endl;
		



	}
}