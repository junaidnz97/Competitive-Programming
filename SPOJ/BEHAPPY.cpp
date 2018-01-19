#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dpfun(vector <int> &a,vector<int> &b,int m,int n)
{

	int i,j;
    vector< vector <int> > dp(m+1,vector<int> (m+1,0));

	for(i=1;i<=n;i++)
	{
        for(j=a[i])
	}
}

int main()
{
	while(1)
	{
		int m,n;
		cin>>m>>n;

		if(m==0 || n ==0)break;


		int g1,g2;
        
        vector <int> a(m),b(m,0);
		for(i=0;i<m;i++)
			cin>>a[i]>>b[i];
        

        dpfun(a,b,m,n);

	}
}