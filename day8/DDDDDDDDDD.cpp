#include<iostream>
#include<cstring>
#include<sstream>
#include<string>
#include<cstdio>
#include<cctype>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
#define fi first
#define se second
#define MP make_pair
#define P pair<int,int>
#define PLL pair<ll,ll>
#define lc (p<<1)
#define rc (p<<1|1)	
#define MID (tree[p].l+tree[p].r)>>1
#define Sca(x) scanf("%d",&x)
#define Sca2(x,y) scanf("%d%d",&x,&y)
#define Sca3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define Scl(x) scanf("%lld",&x)
#define Scl2(x,y) scanf("%lld%lld",&x,&y)
#define Scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define Pri(x) printf("%d\n",x)
#define Prl(x) printf("%lld\n",x)
#define For(i,x,y) for(int i=x;i<=y;i++)
#define _For(i,x,y) for(int i=x;i>=y;i--)
#define FAST_IO std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define STOP system("pause")
#define ll long long
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const double Pi = acos(-1.0);
using namespace std;
template <class T>void tomax(T&a,T b){ a=max(a,b); }  
template <class T>void tomin(T&a,T b){ a=min(a,b); }
const int N=1000+5;
int uck[N],idx=0;
struct Node{
	int u,v;
	Node(int u,int v):u(u),v(v){}
	Node(){}
}edge[N];
int num[N]; 
int find(int x){ return uck[x]==x ? x : uck[x]=find(uck[x]); }

void merge(int x,int y){
	int t1(find(x)),t2(find(y));
	if(t1!=t2) uck[t2]=t1;	
}

void init(int n){
	idx=0;
	For(i,1,n) uck[i]=i;
}
int main(){
	int n; Sca(n);
	init(n);
	For(i,1,n-1){
		int u,v; Sca2(u,v);
		if(find(u)!=find(v)) merge(u,v);		
		else edge[++idx]=Node{u,v};
	}
	int ans=0;
	For(i,1,n)
		if(uck[i]==i) num[++ans]=i;
	cout<<ans-1<<endl;
	for(int i=1;i<ans;i++){
		printf("%d %d %d %d\n",edge[i].u,edge[i].v,num[i],num[i+1]);
	}
}

