    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
    	int n;
    	cin>>n;
    	int i;
        vector<int>a(n);
    	for(i=0;i<n;i++)
    		cin>>a[i];
    	vector<int>minfin(100002,INT_MAX),maxfin(100002,INT_MIN);
    	int maxi=INT_MIN;
    	for (int i = 0; i < n; ++i)
    	{
    		minfin[a[i]]=min(minfin[a[i]],i);
    		maxfin[a[i]]=max(maxfin[a[i]],i);
            maxi=max(maxi,maxfin[a[i]]-minfin[a[i]]+1);
    	}
    	cout<<maxi<<endl;
    	
     
    }
