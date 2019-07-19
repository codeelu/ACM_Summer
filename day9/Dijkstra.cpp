//Dijkstra
#include <iostream>
#include <algorithm>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define next Next
using namespace std;
int e[1110][1110];
int u;
int dis[1100];
int book[1100];
int minn;
int const maxn = 99999999;
int main(){
	int n,m;
	int s,t;
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++) {
	  	if(i==j) e[i][j]=0; 
	  	else e[i][j]=maxn;
	  }
	  int x,y,z;
	  for(int i=1;i<=m;i++){
	  	cin>>x>>y>>z;
	     e[x][y]=min(e[x][y],z);
	     e[y][x]=min(e[y][x],z);
	  }
	  for(int i=1;i<=n;i++)
	    dis[i]=e[s][i];
	  
	  for(int i=1;i<=n;i++) book[i]=0;
	    book[s]=1;
	  
	     for(int i=1;i<=n-1;i++){
	     	  minn=maxn;
	     	for(int j=1;j<=n;j++){
	     	  if(book[j]==0 && dis[j] <minn){
	     	  	minn=dis[j];
	     	  	u=j;
			   }
		 }
		 
		 book[u]=1;
		 for(int v=1;v<=n;v++){
		 	if(e[u][v]<maxn){
		 		if(dis[v]>dis[u]+e[u][v]) dis[v]=dis[u]+e[u][v];
			 }
		 }
	 }
	 cout<<dis[t]<<endl;
	  return 0;
}
