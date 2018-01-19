#include <bits/stdc++.h>
using namespace std;

long long int maxval(long long int a,long long int b)
{
    if(a>b)
        return a;
    else
    return b;
}
long long int constructtree(vector< long long int> &dp,vector< pair <long long int,long long int> > &build,long long int low,long long int high,long long int flag)
{
    if(low==high)
    {
        dp[flag]=build[low].second;
        return dp[flag];
    }

    long long int mid=low+(high-low)/2;

    dp[flag]=maxval(constructtree(dp,build,low,mid,2*flag+1),constructtree(dp,build,mid+1,high,2*flag+2));

    return dp[flag];
}


long long int maxret(vector<long long int>&dp,long long int low,long long int high,long long int flag,long long int x1,long long int x2)
{
    if(x1>high || x2<low)
        return INT_MIN;
    if(x1<=low && x2>=high)
        return dp[flag];

    long long int mid=low+(high-low)/2;

    return max(maxret(dp,low,mid,2*flag+1,x1,x2),maxret(dp,mid+1,high,2*flag+2,x1,x2));
}

long long int ub(vector<pair<long long int,long long int> >&build,long long int x)
{
    long long int low=0,high=build.size()-1;
    while (low <= high)
    {
        long long int mid = low+(high-low)/2;
 
        // if 'x' is less than or equla to arr[mid], 
        // then search in arr[mid+1...h]
        if (build[mid].first <= x)
            low = mid + 1;
 
        // else search in arr[l...mid-1]    
        else
            high = mid - 1;    
    }
     
    // required index
    
    return high;
}
long long int lb(vector<pair<long long int,long long int> >&build,long long int x)
{
    long long int low=0,high=build.size()-1;
    while (low <= high)
    {
        long long int mid = low+(high-low)/2;
 
        // if 'x' is less than or equla to arr[mid], 
        // then search in arr[mid+1...h]
        if (build[mid].first < x)
            low = mid + 1;
 
        // else search in arr[l...mid-1]    
        else
            high = mid - 1;    
    }
     
    // required index
    
    return high;
}
long long int binarysearch(vector<pair<long long int,long long int> >&build,long long int x)
{
     long long int low=0,high=build.size()-1,mid;
     while(low<=high)
     {
        mid=low+(high-low)/2;
        if(build[mid].first==x)
            return mid;
        else if(build[mid].first<x)
            low=mid+1;
        else
            high=mid-1;
     }
     return -1;
}
long long int maxheightright(vector<pair<long long int,long long int> >&build,vector<long long int>&dp,long long int x1,long long int x2)
{

    long long int pos1,pos2;
    //pos1=ub(build,x1);
    //pos2=ub(build,x2);
    //pos1=upper_bound(build.begin(),build.end(), make_pair(x1, numeric_limits<long long int>::min()))-build.begin();
    //pos2=lower_bound(build.begin(),build.end(), make_pair(x2, numeric_limits<long long int>::min()))-build.begin();
    
    
    pos1=upper_bound(build.begin(),build.end(), make_pair(x1, numeric_limits<long long int>::min()))-build.begin();
    if(binarysearch(build,x2)!=-1)
    {
      pos2=lower_bound(build.begin(),build.end(), make_pair(x2, numeric_limits<long long int>::min()))-build.begin();    
    }
    else
    {
        pos2=lower_bound(build.begin(),build.end(), make_pair(x2, numeric_limits<long long int>::min()))-build.begin()-1;
    }


    //cout<<pos1<<" "<<pos2<<endl;

    return maxret(dp,0,build.size()-1,0,pos1,pos2);
    

}
long long int maxheightleft(vector<pair<long long int,long long int> >&build,vector<long long int>&dp,long long int x1,long long int x2)
{

}

long long int shortestpath(vector<pair<long long int,long long int> >&build,vector<long long int>&dp,long long int x1,long long int y1,long long int x2,long long int y2)
{
   if(x1==x2)
   {
     return abs(y1-y2);
   }
   else if(x1<x2)
   {
      //cout<<src.x<<" "<<des.x<<endl;
      long long int temp=maxheightright(build,dp,x1,x2);
 //     cout<<temp<<endl;
      if(y1<=temp)
      {
        return abs(temp+1-y1)+abs(x1-x2)+abs(temp+1-y2);
      }
      else
      {
        return abs(x1-x2)+abs(y1-y2);
      }
   }
   else
   {
       long long int temp=maxheightright(build,dp,x2,x1);
       
       if(y2<=temp)
      {
        return abs(temp+1-y1)+abs(x1-x2)+abs(temp+1-y2);
      }
      else
      {
        return abs(x1-x2)+abs(y1-y2);
      }

   }
}

int main()
{
    long long int n,q,i;
    cin>>n>>q;

    vector< pair <long long int,long long int> > build;

    for(i=0;i<n;i++)
    {
        long long int temp1,temp2;
        cin>>temp1>>temp2;
        build.push_back(make_pair(temp1,temp2));
    }

    sort(build.begin(),build.end());
    
    vector< pair <long long int,long long int> > src,des;
    
    for(i=0;i<q;i++)
    {
        long long int temp1,temp2,temp3,temp4;
        cin>>temp1>>temp2>>temp3>>temp4;
        src.push_back(make_pair(temp1,temp2));
        des.push_back(make_pair(temp3,temp4));
    }

    /*for(i=0;i<n;i++)
    {
        cout<<build[i].first<<" "<<build[i].second<<endl;
    }
    for(i=0;i<q;i++)
    {
        cout<<src[i].first<<" "<<src[i].second<<" "<<des[i].first<<" "<<des[i].second<<endl;
    }*/

    vector<long long int>dp(4*n);

    constructtree(dp,build,0,n-1,0);

    /*for(i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<" ";
    }*/
    ///cout<<endl;
    for(i=0;i<q;i++)
    {
        cout<<shortestpath(build,dp,src[i].first,src[i].second,des[i].first,des[i].second)<<endl;
        //shortestpath(build,dp,src[i].first,src[i].second,des[i].first,des[i].second);
    }
}