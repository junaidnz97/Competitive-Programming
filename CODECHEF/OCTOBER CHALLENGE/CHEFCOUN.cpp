#include <iostream>
#include<vector>
#include<limits.h>
#include<math.h>
using namespace std;


int wrongSolver1(std::vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}

int wrongSolver2(std::vector <unsigned int> a) {

	int n = a.size();
	std::vector<long long int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	long long int mn = (prefSum[0] + sufSum[0]);
	int where = 1;
	for (int i = 1; i < n; i++) {
	long long int val = (prefSum[i] + sufSum[i]);

	//cout<<mn<<endl;
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}

int main()
{


    int it,test;
    cin>>test;
    for(it=0;it<test;it++)
    {
	int n;

	
    cin>>n;
	vector<unsigned int> a(n,1);

	int i;
	//cout<<INT_MAX/99990;


	a[0]=2;
	a[1]=1;

    long long int k=(4294967295-4)/n-2;
    long long int sum=3;
    for(i=2;i<n;i++)
    {
    	if(sum+100000<=4294967294)
    	{
    	a[i]=100000;
    	sum=sum+100000;
        }
        else
        {
        	break;
        }
    }

  a[n-1]=(4294967294-sum)-n+i-1;

//   cout<<i<<endl;
	

/*	if(wrongSolver1(a)==wrongSolver2(a))
	{
		cout<<"true"<<endl;
	}

	else
	{
		cout<<"false"<<endl;
	}*/

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<endl;

	

	
    
    }
}