#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
const int power=30;
int p[N][30];
int deep[N];
int in[N];
struct node
{
	int to;
	int next;
}edge[N];
int head[N],tot;
 
void addedge(int from,int to)
{
	edge[tot].to=to;
	edge[tot].next=head[from];
	head[from]=tot++;
}
 
void dfs(int u,int fa)
{
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==fa)
			continue;
		deep[v]=deep[u]+1;
		dfs(v,u);
	}
}
 
int lca(int a,int b) 
{
	if(deep[a]<deep[b])
	{
		a^=b;
		b^=a;
		a^=b;
	}
	int d=deep[a]-deep[b];
	for(int i=0;i<power;i++)
	{
		if(d&(1<<i))//这个操作很巧妙，利用2进制的思想
			a=p[a][i];
	}
	if(a==b)
		return a;
	for(int i=power-1;i>=0;i--)
	{
 		if(p[a][i]!=p[b][i])//越过他们的LCA之后，这些p值肯定都是一样的，反之，就一定还没到
		 {
			a=p[a][i];
			b=p[b][i];
		}
	}
	return p[a][0];//如果不明白为什么是这个的话，可以自己在纸上模拟下
	
}
 
char str1[55],str2[55];
 
int main()
{
	int n,m;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(in,0,sizeof(in));
	    scanf("%d%d",&n,&m);
	    memset(head,-1,sizeof(head));
	    memset(p,0,sizeof(p));
	    tot=0;
		int cnt=0,i;
		map<string,int>num;
		num.clear();
		for(int i=1;i<=n-1;i++)
		{
			scanf("%s%s",str1,str2);
			if(num[str1]==0)
				num[str1]=++cnt;
			if(num[str2]==0)
				num[str2]=++cnt;
			addedge(num[str2],num[str1]);
			in[num[str1]]++; //点个数 
			p[num[str1]][0]=num[str2]; //父亲 
		}
		for(i=1;i<=cnt;i++)
			if(in[i]==0)
				break;
		deep[i]=0;
		dfs(i,i);
		for(int j=1;j<power;j++)
			for(int i=1;i<=cnt;i++)
				p[i][j]=p[p[i][j-1]][j-1];  //初始化	 
		for(int i=1;i<=m;i++)
		{
			scanf("%s%s",str1,str2);
			int a=num[str1];
			int b=num[str2];
			int c=lca(a,b);
			cout<<"a="<<c<<endl;
			cout<<"b="<<c<<endl;
			cout<<"c="<<c<<endl;
			int ans=deep[a]-deep[c];
			cout<<deep[a]<<' '<<deep[c]<<endl;
			cout<<ans<<endl;
			if(c!=b)
				ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}

