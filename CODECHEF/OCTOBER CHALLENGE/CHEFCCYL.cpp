#include<bits/stdc++.h>
using namespace std;

int main()
{

  long long int it,test;
  cin>>test;
  for(it=0;it<test;it++)
  {
     long long int n,q,i,m,temp,j;
     cin>>n>>q;
    
     vector<vector <long long int > >a; 
     long long int c[100000][3];
     for(i=0;i<n;i++)
     {

       m;
       cin>>m;
       vector <long long int>b;
       for(j=0;j<m;j++)
       {
          cin>>temp;
          b.push_back(temp);   

       }
       a.push_back(b);

     }

     //cout<<"hello"<<endl;

     for(i=0;i<n;i++)
     {

        cin>>c[i][0]>>c[i][1]>>c[i][2];
        

     }

     long long int d[100000][4];
       for(i=0;i<q;i++)
       {
          cin>>d[i][0]>>d[i][1]>>d[i][2]>>d[i][3];
       }



     
     if(n==1)
      {
      	for (int i = 0; i < q; j++)
      	{
      		//scout<<"hello";
      	}
      }


     else
     {
     vector< vector<long long int> > fin;

     


     for(i=0;i<n;i++)
     {

        vector <long long int> b1,b2;
        b1.push_back(a[i][0]);
        long long int m=a[i].size();

        for(j=1;j<m;j++)
        {
              b1.push_back(a[i][j]+b1[j-1]);
        }
        
        long long int esc1,esc2;
        if(i==0)
          esc1=c[n-1][1];
        else
          esc1=c[i-1][1];

        esc2=c[i][0];

      

        
        
        vector<long long int>x1,x2;
        long long int sum=b1[m-1];
        x1.push_back(esc1-1);
        x2.push_back(esc2-1);

        for(j=0;j<m;j++)
        {
          if(esc1==j+1)
            x1.push_back(0);
          else if(esc1==1)
          {
            
              x1.push_back(min(b1[j-1],sum-b1[j-1]));
          }
          else if(j==0)
          {
             x1.push_back(min(b1[esc1-2],sum-b1[esc1-2]));
          }
          else
          {
            x1.push_back(min(abs(b1[esc1-2]-b1[j-1]),sum-abs(b1[esc1-2]-b1[j-1])));
          }

        }

        for(j=0;j<m;j++)
        {
          if(esc2==j+1)
            x2.push_back(0);
          else if(esc2==1)
          {
            
              x2.push_back(min(b1[j-1],sum-b1[j-1]));
          }
          else if(j==0)
          {
             x2.push_back(min(b1[esc2-2],sum-b1[esc2-2]));
          }
          else
          {
            x2.push_back(min(abs(b1[esc2-2]-b1[j-1]),sum-abs(b1[esc2-2]-b1[j-1])));
          }

        }

        

        /*for(j=0;j<m;j++)
          cout<<x1[j]<<" ";
        cout<<endl;
        
        for(j=0;j<m;j++)
          cout<<x2[j]<<" ";
        cout<<endl;*/

        fin.push_back(x1);
        fin.push_back(x2);

       }

      /*for(i=0;i<fin.size();i++)
       {
        for(j=0;j<fin[i].size();j++)
        {
          cout<<fin[i][j]<<" ";

        }
        cout<<endl<<endl;
       }*/
       
       vector <long long int> value1;
       for(i=0,j=0;i<fin.size();i=i+2,j++)
       {

             value1.push_back(fin[i+1][fin[i][0]+1]+c[j][2]);
             //cout<<fin[i+1][fin[i][0]+1]<<" "<<c[j][2]<<" "<<value1[j]<<endl;


       }

       for(i=1;i<value1.size();i++)
       {
         value1[i]+=value1[i-1];
       }

       /*for(i=0;i<value1.size();i++)
       {

           cout<<value1[i]<<" "<<endl;
       }*/
       for(i=0;i<q;i++)
       {
          long long int v1=d[i][0],c1=d[i][1],v2=d[i][2],c2=d[i][3];
          long long int ans1=0,ans2=0;
          long long int sum=value1[value1.size()-1];
          if(c1==1)
          {
            ans1+=value1[c2-2];
            ans1=ans1-fin[2*(c1-1)+1][fin[2*(c1-1)][0]+1]+fin[2*(c1-1)+1][v1];
            ans1=ans1+fin[2*(c2-1)][v2];



          }
          else if (c2==1)
          {
            ans1+=value1[c1-2];
            ans1=ans1-fin[2*(c2-1)+1][fin[2*(c2-1)][0]+1]+fin[2*(c2-1)+1][v2];
            ans1=ans1+fin[2*(c1-1)][v1];
            
          }
          else if(c1<c2)
          {
            ans1+=abs(value1[c1-2]-value1[c2-2]);
            //cout<<value1[c1-2]<<" "<<value1[c2-2]<<" "<<ans1<<endl;
            ans1=ans1-fin[2*(c1-1)+1][fin[2*(c1-1)][0]+1]+fin[2*(c1-1)+1][v1];
            ans1=ans1+fin[2*(c2-1)][v2];
          }
          else
          {

          	ans1+=abs(value1[c1-2]-value1[c2-2]);
            //cout<<value1[c1-2]<<" "<<value1[c2-2]<<" "<<ans1<<endl;
            ans1=ans1-fin[2*(c2-1)+1][fin[2*(c2-1)][0]+1]+fin[2*(c2-1)+1][v2];
            ans1=ans1+fin[2*(c1-1)][v1];

          }

          
          
         if(c1==1)
          {
            ans2+=sum-value1[c2-2];
            ans2=ans2-fin[2*(c2-1)+1][fin[2*(c2-1)][0]+1]+fin[2*(c2-1)+1][v2];
            ans2=ans2+fin[2*(c1-1)][v1];
          }
          else if(c2==1)
          {
            ans2+=sum-value1[c1-2];
            ans2=ans2-fin[2*(c1-1)+1][fin[2*(c1-1)][0]+1]+fin[2*(c1-1)+1][v1];
            ans2=ans2+fin[2*(c2-1)][v2];
          }
          else if(c1<c2)
          {
            ans2+=sum-abs(value1[c1-2]-value1[c2-2]);
            
            ans2=ans2-fin[2*(c2-1)+1][fin[2*(c2-1)][0]+1]+fin[2*(c2-1)+1][v2];
            
            ans2=ans2+fin[2*(c1-1)][v1];
          }
          else
          {
          	ans2+=sum-abs(value1[c1-2]-value1[c2-2]);
            
            ans2=ans2-fin[2*(c1-1)+1][fin[2*(c1-1)][0]+1]+fin[2*(c1-1)+1][v1];
            
            ans2=ans2+fin[2*(c2-1)][v2];
          }

         
         // cout<<ans2<<endl;

          
          cout<<min(ans1,ans2)<<endl;
          //cout<<ans1<<" "<<ans2<<endl;
          //cout<<ans1<<" "<<ans2<<endl;
          
       }



       
}


     

  }
}

