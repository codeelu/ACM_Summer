//floyd
#include <iostream>
#include <algorithm>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define next Next
using namespace std;
int e[110][110];
int a[110][110];
int const maxn = 99999999;
int main(){
	int n,m;
	cin>>n>>m;
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
	  for(int k=1;k<=n;k++)
	     for(int i=1;i<=n;i++)
	        for(int j=1;j<=n;j++){
	         if(i!=j && i!=k && k!=j)
	           e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
		}
	  for(int i=1;i<=n;i++){
	  
	  	for(int j=1;j<=n;j++)
	     	if(j==n) cout<<e[i][j];
	  	    else cout<<e[i][j]<<' '; 
	  	  
	  	cout<<endl;
	  }
	  return 0;
}
