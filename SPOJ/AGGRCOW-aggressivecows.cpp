#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int satisfy(vector <int> &a,int n,int c,int num)
{
	//cout<<"hello";
	int numcows=1,i;
    int pos=a[0];
	for(i=1;i<n;i++)
	{
       if(a[i]-pos>=num)
       {
         pos=a[i];
         numcows++;
       }

       if(numcows==c)
	{
		return 1;
	}
	
	}

	
	
		return 0;
} 

int bsearch(vector <int> &a,int n,int c)
{
	int low,high,mid;
	low=0,high=a[n-1];
	int x;
	int max=0;
	while(low <=high)
	{
		mid=(low+high)/2;
 
        x=satisfy(a,n,c,mid);

        if(x==1)
        {

        	low=mid+1;
             if(max<mid)max=mid;


        }
        else
        {

        	high=mid-1;

        	
        }
	}
	return max;
}

int main()
{
	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
        int n,c,i;
        cin>>n>>c;
		vector <int> a(n);

		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
        sort(a.begin(),a.end());
		cout<<bsearch(a,n,c)<<endl;

	}
}