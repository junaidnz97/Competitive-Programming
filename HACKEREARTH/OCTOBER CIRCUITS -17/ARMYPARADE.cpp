#include <bits/stdc++.h>
using namespace std;

#define mod 2000000033

#include<bits/stdc++.h>
using namespace std;
 

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;      
 
    x = x % p;  
                
 
    while (y > 0)
    {
        
        if (y & 1)
            res = (res*x) % p;
 
       
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
 

long long int modInverse(long long int n, long long int p)
{
    return power(n, p-2, p);
}
 


long long int nCrModPFermat(long long int n, long long int r, long long int p,vector<long long int> &fac)
{
   if (r==0)
      return 1;  
 
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}
 

int main()
{
	long long int n,m,k,i,x=0;

	cin>>n>>m>>k;

	vector<pair<long long int,long long int> > arr;
    
    for(i=0;i<k;i++)
    {
    	long long int temp1,temp2;
    	cin>>temp1>>temp2;
    	arr.push_back(make_pair(temp1,temp2));
    }


    
    long long int size=max(m,n);
    vector<long long int >fac(size+1);
    fac[0] = 1;
    for (long long int i=1 ; i<=size; i++)
        fac[i] = fac[i-1]*i%mod;

    long long int sum=0;
    for(i=1;i<=min(m-1,n-1);i++)
    {
    	sum+=(nCrModPFermat(n-1,i,mod,fac)%mod)*(nCrModPFermat(m-1,i,mod,fac)%mod)%mod;
    }
    
    cout<<(sum+1)*(m*n-k)<<endl;
  

}
