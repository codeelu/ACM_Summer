//Dijkstra
#include <iostream>
#include <algorithm>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define next Next
#define INF 0x3f3f3f3f
using namespace std;
int maxx;
bool cmp(int a,int b)
{
	return a>b;
}
int e[1110][1110];
int e1[1110][1110];
int u1;
int dis[1100];
int dis1[1100];
int u[1100];
int v[1100];
int z[1100];
int book[1100];
int minn=INF;
int n;
void Dijkstra(int s,int dis[]){
	for(int i=1;i<=n;i++)
	    dis[i]=e[s][i];
	  dis[s] = 0;
	  for(int i=1;i<=n;i++) book[i]=0;
	    book[s]=1;
	  
	     for(int i=1;i<=n-1;i++){
	     	  minn=INF;
	     	for(int j=1;j<=n;j++){
	     	  if(book[j]==0 && dis[j] <minn){
	     	  	minn=dis[j];
	     	  	u1=j;
			   }
		 }
		 
		 book[u1]=1;
		 for(int v=1;v<=n;v++){
		 	if(e[u1][v]<INF){
		 		if(dis[v]>dis[u1]+e[u1][v]) dis[v]=dis[u1]+e[u1][v];
			 }
		 }
	 }
}
int main(){
	int m;
	int s,t;
	cin>>n>>m>>s; 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++) {
	  	if(i==j) e[i][j]=0; 
	  	else e[i][j]=INF;
	  }
	int x,y,z;
	  for(int i=1;i<=m;i++){
	  	cin>>x>>y>>z;
	     e[x][y]=min(e[x][y],z);
	  }
	  //
	  Dijkstra(s,dis);
	 
	 //

	//
for(int i = 1; i <= n; i++)            //调转各边，也就是将矩阵转置
		{
			for(int j = 1; j < i; j++)
			{
				int temp = e[i][j];
				e[i][j] = e[j][i];
				e[j][i] = temp;
			}
		}
		  Dijkstra(s,dis1);

	 int mm=0;
 for(int i=1;i<=n;i++){
 	mm=max(mm,dis[i]+dis1[i]);
 }
 cout<<mm<<endl;
	  return 0;
}
