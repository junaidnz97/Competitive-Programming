#include<iostream>
#include<limits.h>
#include<vector>
#include <string.h>
using namespace std;



//testcase12
int unboundedknapsack(int w,int wt[],int val[],int n)
{
	vector <int> dp(1000000,-1);
	 int i,j;
	

	/*for(i=0;i<=w;i++)
		cout<<dp[i]<<" ";
	cout<<endl;
   */
      
    int flag=0;
    dp[0]=0;

    for(i=1;i<=w;i++)
    {

    	for(j=0;j<n;j++)
    	{
    		/*if(i>=wt[j])
    		{
    			if(dp[i-wt[j]]==INT_MAX)dp[i-wt[j]]=0;

    			if(i==w)
                        {
                          if(dp[i-wt[j]]!=0||(dp[i-wt[j]]==0 && i-wt[j]==0))
                          {
                          flag=1;
                          dp[i]=min(dp[i],val[j]+dp[i-wt[j]]);
                          }
                          

                         }
                
                        else
                  
    		    dp[i]=min(dp[i],val[j]+dp[i-wt[j]]);*/

    		if(i>=wt[j] && dp[i-wt[j]]!=-1 && (dp[i]==-1 || val[j]+dp[i-wt[j]]<=dp[i]))
              dp[i] = val[j]+dp[i-wt[j]];

//    	}

  	//cout<<i<<" "<<j<<" "<<dp[i]<<endl;
    	//cout<<dp[i]<<endl;

    	}

    }
    if(dp[w]!=-1)
    {
    	cout<<"The minimum amount of money in the piggy-bank is "<<dp[w]<<"."<<endl;
    }
    else
    {
    	cout<<"This is impossible."<<endl;
    }
    

    //cout<<dp[w]<<" "<<flag<<endl;
    /*for(i=0;i<=w;i++)
		cout<<dp[i]<<" ";
	cout<<endl;*/
    return dp[w];
}

int main()
{
	int it,test;
    cin>>test;
	for(it=0;it<test;it++)
	{

		int e,f,w;
		cin>>e>>f;
		w=f-e;
		int i,n,wt[501],val[501];
        cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>val[i]>>wt[i];
		}

		

		unboundedknapsack(w,wt,val,n);

	}
}
