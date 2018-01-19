#include<iostream>

#include<string.h>
#include<vector>
using namespace std;

//vector <int> sumo(100,0);
//vector <int> sumr(100,0);
vector < vector<int> > dp(100, vector <int> (100,-1));

int ans;

int fun(char s[100],int cur,int prev,int n)
{
	
	if(cur==n)return 1;
    
    int i;
    int sum=0;
    int finans=0;
    for(i=cur;i<n;i++)
    {
        sum+=s[i]-'0';
        if(sum>=prev)
        {
        	
        	finans+=fun(s,i+1,sum,n);
        }
    }
    return finans;
}

int main()
{
	int it=0;

	while(1)
	{
	char s[100];
	cin>>s;
	if(strcmp(s,"bye")==0)return 0;
	int n=strlen(s);
	//cout<<s<<" "<<n;
	int i,j;

	ans=0;

	it++;

	cout<<it<<". "<<fun(s,0,0,n)<<endl;

	
 }
}