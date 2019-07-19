#include <iostream>
#include <algorithm>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define next Next
using namespace std;
int e[1110][1110];

int dis[1100];
int book[1100];
int minn;
int const maxn = 100010;
int next[maxn],ver[maxn],head[maxn],match[maxn];
bool vis[maxn];
int u[maxn],v[maxn],w[maxn];
int first[maxn];
int tot;
void add(int x,int y){
	ver[++tot]=y;
	next[tot]=head[x];
first[x]=tot;
}

int k;
int main(){
	int n,m;
	int s,t;
	cin>>n>>m>>s>>t;
	  int x,y,z;
	  	for(int i=1;i<=n;i++) {
		 book[i]=0;  
		 dis[i]=99999999;
		 }
		 
	  	dis[s]=0;

	for(int i=1;i<=m;i++){
	  cin>>u[i]>>v[i]>>w[i];
	  add(u[i],v[i]); 
	  add(v[i],u[i]);
	} 
	  int tail=1,head=1;
	  int que[maxn]; 
	que[tail]=s;tail++;
	book[s]=1;
while(head<tail){
	
   for(int i=first[que[head]];i;i=next[i]){
   	  k=i;
   	if(dis[v[k]]>dis[u[k]]+w[k]){
   		dis[v[k]]=dis[u[k]]+w[k];
   		if(book[v[k]]==0){
   			que[tail]=v[k];
   			tail++;
   			book[v[k]]=1;
		   }
	   }
	   
   }
  book[que[head]]=0;
  head++;
	  
}
	 cout<<dis[t]<<endl; 
	   
	  return 0;
}
