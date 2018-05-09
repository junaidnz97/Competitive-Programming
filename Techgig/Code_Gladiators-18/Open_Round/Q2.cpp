#include <bits/stdc++.h>
using namespace std;

struct tnode
{
	int par;
	int depth;
	int size;
	int seg_pos;
	int chain_no;
}node[100005];

struct seg_tree
{
	int base[100005];
	int s_tree[400020];
}s;

int n,m,cur_chain=1,node_count=1,u,v,level=15;
vector<vector<int> >g(100005),parent(100005,vector<int>(level,0));
vector<int>visited(100005,0),chain_heads(100005,-1),lazy(400020,0);

int final_update(int node,int start,int end)
{
	if(lazy[node]!=0)
	{
		s.s_tree[node]+=lazy[node];
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
			
		}
		lazy[node]=0;
	}
	if(start==end)
	{
		return 0;
	}
	int mid=(start+end)/2;
	final_update(2*node,start,mid);
	final_update(2*node+1,mid+1,end);

	s.s_tree[node]=max(s.s_tree[2*node],s.s_tree[2*node+1]);
}

int dfs(int cur,int prev,int depth)
{
	visited[cur]=1;
	parent[cur][0] = prev;
	int j;
	node[cur].par=prev;
	node[cur].depth=depth;
	node[cur].size=1;
	for(j=0;j<g[cur].size();j++)
	{
		if(visited[g[cur][j]]==0)
		{
			dfs(g[cur][j],cur,depth+1);
			node[cur].size+=node[g[cur][j]].size;
		}
	}
}

int hld(int cur)
{
	
		if(chain_heads[cur_chain]==-1)
			chain_heads[cur_chain]=cur;
		node[cur].chain_no=cur_chain;
		node[cur].seg_pos=node_count;

		node_count++;
		int j;
		visited[cur]=1;
		int num=-1,max_size=-1;
		for(j=0;j<g[cur].size();j++)
		{
			if(visited[g[cur][j]]==0)
			{
				if(max_size<node[g[cur][j]].size)
				{
					num=g[cur][j];
					max_size=node[g[cur][j]].size;
				}
			}
		}

		if(num!=-1)
		{	
			hld(num);
		}
		for(j=0;j<g[cur].size();j++)
		{
			if(visited[g[cur][j]]==0 && g[cur][j]!=num)
			{
				cur_chain++;
				hld(g[cur][j]);
			}
		}
}


void precomputeSparseMatrix()
{
    for (int i=1; i<level; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (parent[j][i-1] != -1)
                parent[j][i] =
                    parent[parent[j][i-1]][i-1];
        }
    }
}
 

int lca(int x,int y)
{
    if (node[y].depth < node[x].depth)
       { swap(x, y);
       }
 
    int diff = node[y].depth - node[x].depth;
 
    for (int i=0; i<level; i++)
        if ((diff>>i)&1)
            y = parent[y][i];
 
    if (x == y)
        return x;
 
    for (int i=level-1; i>=0; i--)
        if (parent[x][i] != parent[y][i])
        {
            x = parent[x][i];
            y = parent[y][i];
        }
 
    return parent[x][0];
}

int lazy_update(int node,int start,int end,int l,int r,int diff)
{
	if(lazy[node]!=0)
	{
		s.s_tree[node]+=lazy[node];
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>r || end<l|| start>end)
		return 0;

	if(start>=l && end<=r)
	{
		s.s_tree[node]+=diff;
		if(start!=end)
		{
			lazy[2*node]+=diff;
			lazy[2*node+1]+=diff;	
		}
		return 0;
	}
	int mid=(start+end)/2;
	lazy_update(2*node,start,mid,l,r,diff);
	lazy_update(2*node+1,mid+1,end,l,r,diff);
	s.s_tree[node]=max(s.s_tree[2*node],s.s_tree[2*node+1]);	
}

int lca_flag=0;

int crawl_tree(int x,int y)
{
	int chain_u,chain_v=node[y].chain_no,ans=0;
	while(1)
	{
		chain_u=node[x].chain_no;
		if(chain_u==chain_v)
		{

			if(x==y);
			
			else
			{	

				lca_flag=1;
				lazy_update(1,1,n,node[y].seg_pos,node[x].seg_pos,1);
				
			}
			break;
		}
		else
		{
			lazy_update(1,1,n,node[chain_heads[chain_u]].seg_pos,node[x].seg_pos,1);
			x=node[chain_heads[chain_u]].par;
			
		}
	}
}

int update_tree()
{
	lca_flag=0;
	int l_c_a=lca(u,v);	
	crawl_tree(u,l_c_a);
	crawl_tree(v,l_c_a);
	if(lca_flag==0)
	{	
		lazy_update(1,1,n,node[l_c_a].seg_pos,node[l_c_a].seg_pos,1);
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int i,j,temp1,temp2;
	for(i=0;i<400020;i++)
		s.s_tree[i]=0;

	cin>>n>>m;
	for(i=1;i<=n-1;i++)
	{
		cin>>temp1>>temp2;
		g[temp1].push_back(temp2);
		g[temp2].push_back(temp1);
	}
	dfs(1,-1,0);
	precomputeSparseMatrix();
	fill(visited.begin(), visited.end(),0);
	hld(1);	
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		update_tree();		
	}
	
	final_update(1,1,n);
	cout<<s.s_tree[1]<<"\n";
}
