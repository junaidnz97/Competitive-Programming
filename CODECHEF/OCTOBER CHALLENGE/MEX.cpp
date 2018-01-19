#include<bits/stdc++.h>
using namespace std;


int main()
{

	int it,test;
	cin>>test;

	for(it=0;it<test;it++)
	{
		int n,k,i;
        cin>>n>>k;
        set<int> b;
        vector<int>a;
        int temp;
        for(i=0;i<n;i++)
        {
           cin>>temp;
           b.insert(temp);
        }
        n=b.size();
        //sort(a.begin(),a.end());
        set<int>::iterator it;
        for(it=b.begin();it!=b.end();it++)
        {   
        	a.push_back(*it);
        }

      /*  for(i=0;i<n;i++)
        {
        	cout<<a[i]<<" ";
        }
        cout<<endl;
        */


     if(k!=0)
     {

     	int x=0,i=0,count=0,ans=0;

     	while(k>=count)
     	{
     		if(a[i]==x && i<n)
     		{
     			x++;
     			i++;
     		}
     		else
     		{
     			ans=x;
     			x++;
     			count++;
     		}
     	}

     	cout<<ans<<endl;
     }
     else
     {
     	int x=0;
     	for(i=0;i<n;i++)
     	{
     		if(a[i]!=x)
     		{
     			
     			break;
     		}
     		x++;
     	}
     	cout<<x<<endl;
     }
	}
}