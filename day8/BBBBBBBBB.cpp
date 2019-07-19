#include<iostream>
#include<cstring>
using namespace std;
int map[1500][1500]; 
int vis[1500],pre[1500];
struct node
{
	int x,y;
}w[600],b[600];
int g[35][35];//建图 
int n,m,k;
int cnt1 = 1;//黑色 
int cnt2 = 1;//白色 
int dfs(int x)
{
	for(int i=1;i<=cnt2;i++)
	{
		if(vis[i]==0&&map[x][i])
		{
			vis[i] = 1;
			if(pre[i]==0||dfs(pre[i]))
			{
				pre[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(pre,0,sizeof(pre));
		memset(g,-1,sizeof(g));
		for(int i=1;i<=k;i++)
		{
			int x,y;
			scanf("%d%d",&y,&x);
			g[x][y] = 1;//危险区 
		}
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=m;j++)
//				if(g[i][j]!=1)
//					g[i][j] = 0;//可覆盖区 
		//开始染色 建图
		cnt1 = 1;cnt2 = 1;
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=m;j++)
//			{
//				cout<<g[i][j];
//				if(j==m)
//					cout<<endl;
//			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(g[i][j]==1)	
					continue;
				if((i+j)%2==1)//奇数
				{
//					cout<<"!";
						
					b[cnt1].x = i;
					b[cnt1].y = j;
//						cout<<b[cnt1].x<<" "<<b[cnt1].y; 
					cnt1++;
				} 
				else
				{
					w[cnt2].x = i;
					w[cnt2].y = j;
					cnt2++;
				}					
				
			}
		
//		for(int i=1;i<=cnt1;i++)	
//			cout<<b[i].x<<" "<<b[i].y<<"    "<<w[i].x<<" "<<w[i].y<<endl;
//		cout<<--cnt1<<--cnt2;
		cnt1--;cnt2--;
		int cnt = 0;
		for(int i =1;i<=cnt1;i++)
			for(int j=1;j<=cnt2;j++)//建树 左边是黑 
			{
				int dx = abs(b[i].x-w[j].x);
				int dy = abs(b[i].y-w[j].y);
				if((dx==1&&dy==0)||(dx==0&&dy==1))//纵坐标差一 横坐标相等 
				{
//					cout<<"dx"<<dx<<"dy"<<dy<<endl; 
//					cnt++;
					map[i][j] = 1;
				}
//				cout<<map[i][j]<<" ";
			}
//		cout<<"cnt"<<cnt<<endl;; 
		
		int ans=0; 
		for(int i =1;i<=cnt1;i++)
		{
			memset(vis,0,sizeof(vis));
			ans+=dfs(i); 
		}
		
//		printf("%d",ans);
		if(cnt1!=cnt2)//黑白数目不一样
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

