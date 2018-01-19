#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 vector <int> a(100,0);
 int n;
 int counttot;

int bsearch(vector <int> &partb,int n,int p)
{
	//cout<<"test1"<<endl;
	int low=0,high=n;
    int mid=(low+high)/2;
	while(low<=high)
	{
		mid=(low+high)/2;
	//	cout<<"test3"<<endl;
		if(partb[mid]==p)
		{
	//		cout<<"test2"<<endl;

			//counttot++;
			return 1;
		}
		else if(partb[mid]>p)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return -1;
}

/*int fun()
{
	vector <int> parta,partb;

	int i,j,k;
	int counta=0,countb=0;

	//cout<<"hello1"<<endl;

	for(i=0;i<=n/2;i++)
	{
		for(j=0;j<=n/2;j++)
		{
			for(k=0;k<=n/2;k++)
			{
			  cout<<(a[i]*a[j])+a[k]<<endl;
              parta.push_back((a[i]*a[j])+a[k]);
              counta++;
			}
		}
	}
	cout<<counta<<endl;


	for(i=0;i<counta;i++)
	{
		cout<<parta[i]<<" ";
	}
	cout<<endl;

	//cout<<"hello2"<<endl;

	for(i=n/2 +1;i<n;i++)
	{
		for(j=n/2 +1;j<n;j++)
		{
			for(k=n/2 +1;k<n;k++)
			{
              partb.push_back((a[i]+a[j])*a[k]);
              countb++;
			}
		}
	}
	//cout<<"hello3 "<<counta<<" "<<endl;

	for(i=0;i<countb;i++)
	{
		cout<<partb[i]<<" ";
	}
	cout<<endl;

	sort(partb.begin(),partb.end());

	for(i=0;i<counta;i++)
	{
       bsearch(partb,countb-1,parta[i]);
	}


}*/

int fun()
{

	vector <int> parta,partb;

	int i,j,k;
	int counta=0,countb=0;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				parta.push_back((a[i]*a[j])+a[k]);
				counta++;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a[k]!=0)
				{
				partb.push_back((a[i]+a[j])*a[k]);
				countb++;
			    }
			}
		}
	}

	sort(partb.begin(),partb.end());

	for(i=0;i<counta;i++)
	{ 
	   //cout<<parta[i]<<" ";
       counttot+=upper_bound(partb.begin(),partb.end(),parta[i])-lower_bound(partb.begin(),partb.end(),parta[i]);
       
	}
	

	

}



int main()
{
  
  

   int i;

   cin>>n;
   counttot=0;

   for(i=0;i<n;i++)
   {
   	cin>>a[i];
   }

   fun();
   cout<<counttot<<endl;
}