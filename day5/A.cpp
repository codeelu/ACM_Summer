#include <bits/stdc++.h>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
int const maxn = 10010;
vector<int> son[10010];
int f[10010][2],v[10010],h[10010],n;
void dp(int x){ //
	f[x][0]=0;
	f[x][1]=h[x];//
	for(int i=0;i<son[x].size();i++){
		int y=son[x][i];
		dp(y);
		f[x][0]+=max(f[y][0],f[y][1]);
		f[x][1]+=f[y][0];
	}
	
} 
int main(){
	while(cin>>n){
		memset(h,0,sizeof(h));
			memset(v,0,sizeof(v));
				memset(f,0,sizeof(f));
		for(int i=1;i<maxn;i++)
		  son[i].clear();
		for(int i=1;i<=n;i++) 
		  cin>>h[i];
		for(int i=1;i<=n;i++){
			int a,b;
			cin>>a>>b;
			if(a==0 && b==0)
			   break;
			v[a]=1;// 不是根节点 
			son[b].push_back(a);//  b是a 父亲 
			
		}
		int root;
		for(int i=1;i<=n;i++){
			if(v[i]==0){ //没有父亲 
				root=i;
				break;
			}
		} 
		dp(root);
		int a1,b1;
	
		cout<<max(f[root][1],f[root][0])<<endl;
	}
}

