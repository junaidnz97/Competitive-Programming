#include<limits.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
#define INF 1000000
long long int count;
vector <long long int> dp(1000000,INF);
vector <long long int> wt(47,0);

int initwt()
{
	int i;

	for(i=0;i<=46;i++)
	{
      wt[i]=(i+1)*(i+1)*(i+1);
	}

	/*for(i=0;i<46;i++)
	{
      cout<<wt[i]<<" ";
	}
	cout<<endl;*/
}

void unboundedknapsack()
{


	initwt();
	long long int i,j;
    
	
    for(i=3;i<=100001;i++)
    {

    	for(j=0;j<=46;j++)
    	{
    		

    		if(i-wt[j]>=0)
    		{
    			
    			dp[i]=min(dp[i],1+dp[i-wt[j]]);
    		}





    	}

    }

  /*  for (int i = 0; i <=100001; ++i)
    {
    	cout<<dp[i]<<" ";
    }*/
    
    
}

int main()
{
	count=1;
	int w;

    dp[1]=1;
    dp[2]=2;
    dp[0]=0;

    unboundedknapsack();
    


	while(scanf("%d",&w)!=EOF)
	{
       
       

       

       cout<<"Case #"<<count<<": "<<dp[w]<<endl;
       count++;
    

     

       
	}
	return 0;
}
