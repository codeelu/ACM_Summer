#include <bits/stdc++.h>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define next Next
using namespace std;
int map[1500][1500]; 
int pre[1500];
int const maxn = 1010;
int k,m,n;
int tot;
int next[maxn],ver[maxn],head[maxn],match[maxn];
bool vis[maxn];
int ans;
void add(int x,int y){
	ver[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}
bool dfs(int x){
	for(int i=head[x],y;i;i=next[i]){
		y=ver[i];
		if(!vis[y]) {
			vis[y]=1;
			if(!match[y] || dfs(match[y])){
				match[y]=x;return true;
			}
		}
	}
	return false;
}
struct node
{
	int x,y;
}w[600],b[600];
int g[35][35];//建图 
int cnt1 = 1;//黑色 
int cnt2 = 1;//白色 

int main()
{
	FAST_IO;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
    ans=0;
    tot=0;
	memset(ver,0,sizeof(ver));
	memset(next,0,sizeof(next));
	memset(head,0,sizeof(head));
	memset(match,0,sizeof(match));
	//	memset(pre,0,sizeof(pre));
		memset(g,-1,sizeof(g));
		for(int i=1;i<=k;i++)
		{
			int x,y;
	     	cin>>x>>y; 
			g[x][y] = 1;//危险区 
		}

		//开始染色 建图
		cnt1 = 1;cnt2 = 1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(g[i][j]==1)	
					continue;
				if((i+j)%2==1)//奇数
				{
						
					b[cnt1].x = i;
					b[cnt1].y = j;

					cnt1++;
				} 
				else
				{
					w[cnt2].x = i;
					w[cnt2].y = j;
					cnt2++;
				}					
				
		}
		cnt1--;cnt2--;
		int cnt = 0;
		for(int i =1;i<=cnt1;i++)
			for(int j=1;j<=cnt2;j++)//建树 左边是黑 
			{
				int dx = abs(b[i].x-w[j].x);
				int dy = abs(b[i].y-w[j].y);
				if((dx==1&&dy==0)||(dx==0&&dy==1))//纵坐标差一 横坐标相等 
				{
                    add(i,j);
					//map[i][j] = 1;
				}
			}
		int ans=0; 
		for(int i =1;i<=cnt1;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ++ans;
		}
		

		if(cnt1!=cnt2) //黑白数目不一样
		{
			printf("NO\n");
			continue;
		} 
		if(ans==cnt1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}


