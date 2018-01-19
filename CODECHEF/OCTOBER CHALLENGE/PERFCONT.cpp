#include <iostream>
#include<vector>
#include<limits.h>
#include<math.h>
using namespace std;

int main()
{
	int it,test;
	cin>>test;

	for(it=0;it<test;it++)
	{
		int n,p;
		cin>>n>>p;

		int i;
		vector<int> a(n);
        int cw=0,hd=0;
		for(i=0;i<n;i++)
		{
          cin>>a[i];
        }

        for(i=0;i<n;i++)
        {
        	if(cw>1 || hd>2)
        		break;

        	if(a[i]<=(p/10))
        		hd++;
            if(a[i]>=p/2)
            	cw++;
        }

        if(cw==1 && hd==2)
        	cout<<"yes"<<endl;
        else
        	cout<<"no"<<endl;


	}
}