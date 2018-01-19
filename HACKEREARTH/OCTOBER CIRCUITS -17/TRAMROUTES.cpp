

    #include<bits/stdc++.h>
    using namespace std;
     
    struct node
    {
    	int price;
    	int routeno;
    	vector<int> stops;
    };
     
    bool compareByPrice(const node &a, const node &b)
    {
        return a.price < b.price;
    }
     
    int binarysearch(vector<int> &a,int p)
    {
     
        int low=0,high=a.size()-1;
        while(low<=high)
        {
        	int mid=low+(high-low)/2;
        	if(a[mid]==p)
        		return mid;
        	else if(a[mid]>p)
        		high=mid-1;
        	else
        		low=mid+1;
        }
        return -1;
    }
     
    int main()
    {
    	int n,m,q,i,j,k;
    	cin>>n>>m>>q;
     
    	vector<node>route(n);
    	int routeno=1;
    	for(i=0;i<m;i++)
    	{
    	  node x;
    	  x.routeno=routeno;
    	  routeno++;
          cin>>x.price;
          int k;
          cin>>k;
          for(j=0;j<k;j++)
          {
          	int temp;
          	cin>>temp;
          	x.stops.push_back(temp);
          }
          sort(x.stops.begin(),x.stops.end());
          route[i]=x;
    	}
        
        sort(route.begin(),route.begin()+n,compareByPrice);
    	
    	vector<vector<int> > res(q,vector<int>(2,0));
        //set<int>tempres;
    	for(i=0;i<q;i++)
    	{
           cin>>res[i][0]>>res[i][1];
          // int temp1,temp2;
           //cin>>temp1>>temp2;
           //tempres.insert(temp1);
           //tempres.insert(temp2);
           sort(res[i].begin(),res[i].end());
    	}
         //set<int>::iterator it;

         //vector<int>res;
         
         /*for(it=tempres.begin();it!=tempres.end();it++)
         {
            res.push_back(*it);
         }*/
     
    	for(i=0;i<n;i++)
    	{
    		cout<<route[i].price<<" ";
    		for(j=0;j<route[i].stops.size();j++)
    			cout<<route[i].stops[j]<<" ";
    		cout<<endl;
    	}
     

    	for(i=0;i<res.size();i++)
    	{
           cout<<res[i][0]<<" "<<res[i][1]<<endl;
            //cout<<res[i]<<" ";
    	}
        cout<<endl;
        
 

    }

