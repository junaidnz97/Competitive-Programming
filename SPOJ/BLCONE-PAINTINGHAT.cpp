#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double value=0.000001;
int r,h;
long double c1,c2,c3;
long double ans;
long double mid,temp;
long double low=0,high=100;
long double s;

long double binarysearch()
{
	low=0,high=200;
	

	while(low<high)
	{
		//cout<<"test1";
	  mid=(low+high)/2;

      temp=c1*mid*mid*mid+mid*mid*c2+c3;

      if(temp<value && temp>-value)
      {
      	return mid;
      }
      else if(temp>-value)
      {
        high = mid;
      }
      else
      {
      	low=mid;
      }
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	 cin.tie(0);
	int it,test;
	cin>>test;

	for(it=0;it<test;it++)
	{
		
		

		cin>>r>>h;
        
        s=sqrt(r*r+h*h);
        c1=r,c2=3*s,c3=-6*h*h*s;
        
         ans=binarysearch();
          
         if(ans>h)
         {

         	cout<<fixed<<setprecision(6)<<h<<endl;
         }
         else
         	cout<<fixed<<setprecision(6)<<ans<<endl;

        

	}
}