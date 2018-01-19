#include<iostream>
#include<vector>
using namespace std;

int main()
{

	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		char a[2000],b[2000];

        cin>>a;

        int i,n=0;

        for(i=0;a[i]!='\0';i++)
        {
        	if(a[i]=='K' || a[i]=='E')
        		b[n++]=a[i];
        }

        b[n]='\0';
        cout<<b<<endl;

        vector <int> dp(n,0);
        int count=0,dpcount=0,temp;

        for(temp=0;temp<n;temp++)
        	if(b[temp]=='K') break;

        for(i=temp+1;i<n;i++)
        {
        	if(b[i]=='K')break;

        	else if(b[i]=='E')
        		count++;

        }

        dp[0]=count;
        temp=i;
        dpcount=1; 
        count=0;
        for(i=temp+1;i<n;i++)
        {
        	if(b[i]=='E')
        		count++;
        	if(b[i]=='K')
        	{
        		dp[dpcount]=(dp[dpcount-1]+count)*2;
        		dpcount++;
        		count=0;
        	}
        }
       cout<<"hello";
       for(i=0;i<=dpcount;i++)
       	cout<<dp[i]<<" ";
       cout<<endl;
        cout<<dp[dpcount-1]<<endl;
	}

    
}