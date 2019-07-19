#include <bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int y;
}a[205];
struct node1{
	int u;
	int v;
	double s;
}f[200005];
bool cmp(node1 x,node1 y)
{
	return x.s<y.s;
}
int fa[205];
int find(int x)
{
	if(fa[x]==x) return x;
	
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y)
{
	int a=find(x);
	int b=find(y);
	
	if(a!=b)
	{
		fa[a]=b;
		return true;
	}
	return false;
}
int main()
{
	int n,ss=1;
	while(cin>>n && n!=0)
	{
		int num=1;
		for(int i=1;i<=n;i++)
		fa[i]=i;
		for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			f[num].u=i;
			f[num].v=j;
			f[num++].s=sqrt(pow((a[i].x-a[j].x),2)+pow((a[i].y-a[j].y),2));
		}
		sort(f+1,f+1+num,cmp);
		double ans;
		
		for(int i=1;i<=num;i++)
		{
			if(merge(f[i].u,f[i].v))
			{
				ans=f[i].s;
				
			}
		}
		printf("Scenario #%d\n",ss++);
		printf("Frog Distance = %.3f\n",ans);
		cout<<endl;
	}
	return 0;
}

