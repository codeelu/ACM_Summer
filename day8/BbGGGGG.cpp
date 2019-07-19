#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define next Next
#define left cnt1
#define right cnt2
using namespace std;
int const maxn = 3000;
int x1,y1;
int k,m,n;
int tot;
int left=1;
int right=1;
int next[maxn],ver[maxn],head[maxn],match[maxn];
bool vis[maxn];
int map[maxn][maxn];
int ans;
//void add(int x,int y){a
//	ver[++tot]=y;
//	next[tot]=head[x];
//	head[x]=tot;
//}

bool dfs(int x)
{
	for(int i=1;i<=right;i++)
	{
		if(vis[i]==0&&map[x][i])
		{
			vis[i] = 1;
			if(match[i]==0||dfs(match[i]))
			{
				match[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
//int id(int x, int y){
//    return (x - 1) * n + y;
//}
struct node{
	int x,y;
}l[maxn],r[maxn];
int g[35][35];

int main(){
	FAST_IO;
	while(cin>>n>>m>>k){
	ans=0;
    tot=0;
	memset(ver,0,sizeof(ver));
	memset(next,0,sizeof(next));
	memset(head,0,sizeof(head));
	memset(match,0,sizeof(match));
	memset(map,0,sizeof(map));
	memset(g,-1,sizeof(g));
		while(k--){
		 int x,y;
		 cin>>x>>y;
		 g[y][x]=1;
		}
	left=1;right=1;
	for(int i=1;i<=n;i++){   //½¨Í¼ 
		for(int j=1;j<=m;j++){
			if(g[i][j]!=1){
				if((i+j)%2==1){
					l[left].x=i;
					l[left].y=j;
					left++;
				}
				else
				{
					r[right].x=i;
					r[right].y=j;
					right++; 
				}
			}
		}
	}
	left--;
	right--;
	int cnt=0;
	int k=0;
	for(int i=1;i<=left;i++) {//½¨Ê÷ 
	  for(int j=1;j<=right;j++){
	  	int dx=abs(l[i].x-r[j].x);
	  	int dy=abs(l[i].y-r[j].y);
	  	if((dx==1&&dy==0)||(dx==0 && dy==1))
	        map[i][j]=1;
		
		  	// add(x1,y1);
		  	
		 
	  	 
	  }
	}
	ans=0;
	for(int i=1;i<=left;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ++ans;
	}
	if(left!=right) {
		cout<<"NO"<<endl;
		continue;
	}
	if(ans==left) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
}
