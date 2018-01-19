# include <stdio.h>
# include <math.h>
#include<iostream>
using namespace std; 
 int a[100],count;

int pf(int n)
{
   count=0;
   int flag=0;
   //cout<<n<<endl<<endl;
    while (n%2 == 0)
    {
    	//cout<<"test";
    	if(flag==0)
    {
    	flag=1;
    	count++;
	}
        //cout<<"2 count"<<count;
        n = n/2;
        
    }
 
    
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
       flag=0;
        while (n%i == 0)
        {
        //    cout<<n<<" "<<i<<endl;
          //  cout<<i<<" count"<<count;
            if(flag==0)
            {
            	flag=1;
            	count++;
            	
			}
            n = n/i;
        }
    }
    
    if(count>=3)
            	 return 1;
 
    
    if (n > 2 && count>=2)
    {
    //  cout<<count;	
    	return 1;
	}
	else
	{
		return 0;
	}
}
 
 int main()
 {
 	int it,test;
 	cin>>test;
 	for(it=0;it<test;it++)
 	{
 		int n,j;
 		cin>>n;
 		int i=1;
 		int count2=0;
 		
 		while(count2!=n)
 		{
 			if(pf(i)==1)
 			{
 				count2++;
 				
 				i++;
			 }
			 else
			 {
			 	i++;
			 }
 			
		 }
		 cout<<i-1<<endl;
	 }
	 //pf(49);
 }
