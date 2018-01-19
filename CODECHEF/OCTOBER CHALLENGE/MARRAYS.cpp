#include<bits/stdc++.h>
using namespace std;
#define INF INT_MIN

int dpfunrev(vector<vector <long long int> > &a)
{

	long long int i,j,k;

	long long int n=a.size();

	long long int finans=INF,maxi;

	sort(a[n-1].begin(),a[n-1].end());


	vector<long long int>dpo,dpn;

    
	for(i=0;i<a[n-2].size();i++)
	{
		dpo.push_back(max(abs(a[n-2][i]-a[n-1][0])*(n-1),abs(a[n-2][i]-a[n-1][a[n-1].size()-1])*(n-1)));
		finans=max(dpo[i],finans);
		//cout<<dpo[i]<<endl;
	}

	for(i=n-3;i>=0;i--)
	{
		long long int temp1=a[i].size(),temp2=a[i+1].size();

		for(j=0;j<a[i].size();j++)
		{
			maxi=INF;
			for(k=0;k<a[i+1].size();k++)
			{
			

				//maxi=max(maxi,dpo[k]+(abs(a[i][j]-a[i+1][(k+a[i+1].size()+1)%a[i+1].size()]))*(i+1));

				/*if(k==temp2-1)
					maxi=max(maxi,dpo[k]+(abs(a[i][j]-a[i+1][0])*(i+1)));
				else
					maxi=max(maxi,dpo[k]+abs(a[i][j]-a[i+1][k+1])*(i+1));*/

				k==temp2-1?maxi=max(maxi,dpo[k]+(abs(a[i][j]-a[i+1][0])*(i+1))):maxi=max(maxi,dpo[k]+abs(a[i][j]-a[i+1][k+1])*(i+1));

				//cout<<maxi<<endl;
			}
			//dpn[j]=maxi;
			dpn.push_back(maxi);

			finans=max(maxi,finans);
		}
		dpo=dpn;
		dpn.clear();
	}

	//for(i=0;i<a[0].size();i++)
	//	cout<<dpo[i]<<" ";
	//cout<<endl;


    cout<<finans<<endl;




}


int main()
{
	ios::sync_with_stdio(false);
	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		long long int n;
		cin>>n;

		
		

		long long int i,j;
		vector<vector<long long int> >a;

		for(i=0;i<n;i++)
		{
			vector<long long int> b;
			long long int m;
			cin>>m;
			for(j=0;j<m;j++)
			{
                int temp;
                cin>>temp;
				b.push_back(temp);

			}
			a.push_back(b);

			
		}
		/*cout<<a.size()<<endl;
		for(j=0;j<a.size();j++)
			{
				cout<<a[j].size()<<endl;
			}*/
		if(n==1)
			cout<<"0"<<endl;
		else
		dpfunrev(a);

	
}
}