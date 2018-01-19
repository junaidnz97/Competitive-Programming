#include <iostream>
#include <algorithm>
#include <string>
#include<vector>
using namespace std;

long long int max(long long int a,long long int b )
{
	if(a>b)return a;
	else
		return b;
}

long long int bsearch(vector<long long int> &b,long long int low,long long int high,long long int p)
{
	long long int mid;
	while(low<=high)
	{
		mid=(low+high)/2;

		if(b[mid]==p)return mid;

		else if(b[mid]>p)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

long long int fun(vector<long long int> &a,vector<long long int> &b,long long int m,long long int n)
{
	long long int i,j;
	/*for(i=0;i<m;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;

    for(i=0;i<n;i++)
	   {
		     cout<<b[i]<<" ";
	   }
    */
    vector < long long int > suma(m,0),sumb(n,0);

    suma[m-1]=a[m-1];

    for(i=m-2;i>=0;i--)
    {
    	suma[i]=suma[i+1]+a[i];
    }

    sumb[n-1]=b[n-1];

    for(i=n-2;i>=0;i--)
    {
    	sumb[i]=sumb[i+1]+b[i];
    }

    /*for(i=0;i<m;i++)
		{
			cout<<suma[i]<<" ";
		}
		cout<<endl;

    for(i=0;i<n;i++)
	   {
		     cout<<sumb[i]<<" ";
	   }
       cout<<endl;*/
    
    long long int preva=0,prevb=0;
    long long int sum=0;
    for(i=0;i<m;i++)
    {
    	//cout<<"hello";
         //low=lower_bound(b.begin(),b.begin()+m,a[i]);
         j=bsearch(b, 0,n, a[i]);
         //cout<<a[i]<<" "<<j<<endl;
         if(j!=-1)
         {
         	sum+=max(suma[preva]-suma[i],sumb[prevb]-sumb[j]);
         	//cout<<suma[preva]-suma[i]<<" "<<sumb[prevb]-sumb[j]<<endl;
         	prevb=j;
         	preva=i;
         }
         //cout<<j<<" "<<prev<<endl;
    }
    sum+=max(suma[preva],sumb[prevb]);
    return sum;




}

int main()
{

	while(1)
	{
		long long int m,i,n;
		cin>>m;
		if(m==0)return 0;

		vector<long long int> a(10000,0);
		for(i=0;i<m;i++)
		{
			cin>>a[i];
		}
        
        cin>>n;
        vector<long long int> b(10000,0);
        for(i=0;i<n;i++)
        {
        	cin>>b[i];

        }

        
        if(m>n)
		cout<<fun(a,b,m,n)<<endl;
	    else
	    	cout<<fun(b,a,n,m)<<endl;



	}
}