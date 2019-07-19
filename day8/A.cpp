#include <bits/stdc++.h>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define next Next
using namespace std;
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
int main(){
	while(cin>>k>>m>>n && k!=0){
    ans=0;
    tot=0;
	memset(ver,0,sizeof(ver));
	memset(next,0,sizeof(next));
	memset(head,0,sizeof(head));
	memset(match,0,sizeof(match));
	while(k--){
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	for(int i=1;i<=m;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ++ans;
	}
	cout<<ans<<endl; 
		}
}
