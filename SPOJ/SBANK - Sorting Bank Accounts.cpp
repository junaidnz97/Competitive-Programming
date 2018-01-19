#include<iostream>
#include<string.h>
using namespace std;
#include <cstdio>
struct node
{
	char s[100];
	int count;
	
	node *left;
	node *right;
};

node *insert(node *head,char s[100])
{
	if(head == NULL)
	{
		head=new node;
		head->left=NULL;
		head->right=NULL;
		head->count=1;
		strcpy(head->s,s);
		return head;
	}
	else if(strcmp(head->s,s)>0)
	{
		head->left=insert(head->left,s);
	}
	else if(strcmp(head->s,s)<0)
	{
		head->right=insert(head->right,s);
	}
	else
	{
		head->count++;
	}
	return head;
	
	
	
}


void printans(node *head)
{
	if(head!=NULL)
	{
		
		printans(head->left);
		cout<<head->s<<" "<<head->count<<endl;
		printans(head->right);
	}
}

int main()
{
	
	
	int it,test;
	cin>>test;
	for(it=0;it<test;it++)
	{
		int n;
		cin>>n;
		getchar();
		char s[100];
		int i;
		node *head=NULL;
		for(i=0;i<n;i++)
		{
		
		gets(s);
		//cout<<"hello";
	    head=insert(head,s);	
		
	    }
	    cout<<endl;
	    printans(head);
	    cout<<endl;
		
	}
}
