#include<bits/stdc++.h>
using namespace  std;

int main()
{
	long long int n,i,temp;
	cin>>n;
	vector<long long int>a(n+1);
	for(i=0;i<=n;i++)
	{
       cin>>a[i];
	}
	
    int flag=1,j;
	for(j=n;j>=0;j--)
	{
        
        if(a[j]!=0 && j!=0)
        {
        	if(j%2==0)
        	{
        		
                if(a[j]>0)
                {
                	flag=0;
        		cout<<"1"<<" 1"<<endl;
        		break;
        	    }
        	    else if(a[j]<0)
        	    {
        	    	flag=0;
        	    	cout<<"-1"<<" -1"<<endl;
        	    	break;
        	    }
        	}
        	else
        	{
                 if(a[j]>0)
                 {
                 	flag=0;
                 	cout<<"1"<<" -1"<<endl;
                 	break;
                 }
                 else if(a[j]<0)
                 {
                 	flag=0;
                 	cout<<"-1"<<" 1"<<endl;
                 	break;
                 }
        	}
        }
        else if(a[j]!=0 && j==0)
        {
        	if(a[j]>0)
        	{
        		flag=0;
        		cout<<"1"<<" 1"<<endl;
        		break;
        	}
        	else if(a[j]<0)
        	{
        		flag=0;
        		cout<<"-1"<<" -1"<<endl;
        		break;
        	}
        }


	}
	if(flag==1)
		cout<<"0"<<" 0"<<endl;

	
}