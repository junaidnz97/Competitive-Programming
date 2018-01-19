#include<iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}


int main()
{
	while(1)
	{
	
 long long int n,k;
  cin>>n>>k;
  if(n==-1 && k==-1)
  break;
  
  long long int sum=0;
  

    sum=k*(k-1)/2;
	sum=(sum-(k/2))/2;
	
//	cout<<sum<<endl;
long long int q=n*(n-1)/2;
//cout<<q<<endl;
if(sum==0)
cout<<"0"<<endl;
else
{

long long int div=gcd(sum,q);
//cout<<div<<endl;
sum=sum/div;
q=q/div;

if(sum!=q)
cout<<sum<<"/"<<q<<endl;
else
cout<<"1"<<endl;
}
}
}
