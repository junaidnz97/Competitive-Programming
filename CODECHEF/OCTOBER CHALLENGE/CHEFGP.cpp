#include<bits/stdc++.h>
using namespace std;



int main()
{
	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{

		char s[100000];
		int la,lb,i,a=0,b=0,x=1,j,counta=0,countb=0;
		cin>>s;
		//cout<<"test";
		cin>>la>>lb;
		int n=strlen(s);

	    for(i=0;i<n;i++)
	    {
           if(s[i]=='a')
           	a++;
           else
           	b++;
	    }
         
        string str="";
        string str2="";


	    if(a>=b)
	    {
	    	for(i=0;i<b;i++)
	    	{
	    		str+="a";
	    		str+="b";
	    		counta++;
	    		countb++;
	    	}
	    	//a=a-i;
	    	//cout<<a<<" "<<str<<endl;

	         for(i=0;i<2*b;i++)
	         {
	    	   if(i%2==0 )
	    	   {
	    		for(j=0;j<la-1&&counta<a;j++)
	    		{
	    			str2+="a";
	    			counta++;
	    		}
	    	   }
	    	str2+=str[i];
	    }
	    while(counta<a)
	    {
	    	str2+="a";
	    	counta++;
	    }
	   // cout<<str2<<endl;
	    }

	    else
	    {


	    	for(i=0;i<a;i++)
	    	{
	    		str+="b";
	    		str+="a";
	    		counta++;
	    		countb++;
	    	}
	    	//a=a-i;
	    	//cout<<a<<" "<<str<<endl;

	         for(i=0;i<2*a;i++)
	         {
	    	   if(i%2==0 )
	    	   {
	    		for(j=0;j<lb-1&&countb<b;j++)
	    		{
	    			str2+="b";
	    			countb++;
	    		}
	    	   }
	    	str2+=str[i];
	    }
	    while(countb<b)
	    {
	    	str2+="b";
	    	countb++;
	    }




	    }



        str.assign(str2);
	    counta=0,countb=0;
	    for(i=0;i<n;i++)
	    {
          if(str[i]=='a')
          {
          	counta++;
          	countb=0;
          }
          else if(str[i]=='b')
          {
          	countb++;
          	counta=0;
          }
          if(counta==la+1)
          {
          	cout<<"*";
          	counta=1;
          	
          }
          else if(countb==lb+1)
          {
          	cout<<"*";
          	countb=1;
          }
          cout<<str[i];
	    }
	    cout<<endl;

	   

	 }
}
