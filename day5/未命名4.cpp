#include <bits/stdc++.h>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
int n,m,t,k;
int const maxn = 200010;
int f[maxn>>1][25],d[maxn>>1],dist[maxn>>1];
int in[maxn>>1];
int ver[maxn],Next[maxn],head[maxn];
int tot;
//int z;
int vis[maxn>>1];
map<string,int>mp;

void add(int x, int y){
	ver[++tot]=y;//edge[tot]=z;
	Next[tot]=head[x];head[x]=tot;
} 
void dfs(int u,int fa){
	if(vis[u]) return ;
	 vis[u]=1;
	 f[u][0]=fa;
	 for(int i=head[u];i;i=Next[i]){
	 	int v=ver[i];
	 	d[v]=d[u]+1;
	 	dfs(v,u);
	 }
}
void init(){
	   for (int j = 1; j <= 20; j++){
        for (int i = 1; i <= n; i++){
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
}
int lca(int x,int y)
{
	if(d[x]>d[y]) swap(x,y);
	for(int i=20;i>=0;i--)
	  if(d[f[y][i]]>=d[x]) y=f[y][i];
	  if(x==y) return x;
	  for(int i=20;i>=0;i--)
	   if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	   return f[x][0];
}
int main(){
	FAST_IO;
	cin>>t;
	while(t--){
	memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(head));
    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));
		string name1,name2;
		mp.clear();
		cin>>n>>m;
		int temp=0;
		for(int i=1;i<n;i++){
			cin>>name1>>name2;
			if(mp[name1]==0) mp[name1]=++temp;
			if(mp[name2]==0) mp[name2]=++temp;
			in[mp[name1]]++;
			add(mp[name2],mp[name1]);
		}
	for(int i=1;i<=n;i++){
		if(in[i]==0) {
			k=i;break;
		}
	}
	dfs(k,k);
//	cout<<"k="<<k<<endl;
//	for(int i=1;i<=n;i++) cout<<"di"<<d[i]<<' '<<endl;
	init();
	while(m--){
		cin>>name1>>name2;
		int u=mp[name1],v=mp[name2];
		int ff=lca(u,v);
	//	cout<<"ff="<<ff<<endl;
		//cout<<"u="<<u<<" "<<"v="<<v<<endl;
		if(u==v) cout<<0<<endl;
		else if (ff==u) cout<<1<<endl;
		else
		{
			int ans=d[u]-d[ff];
			//	cout<<"d[u]"<<d[u]<<" "<<"d[ff]"<<d[ff]<<endl;
		if(u==v) cout<<0<<endl;
			if(v!=ff) ans++;
			cout<<ans<<endl;
		}
	}
}
}
