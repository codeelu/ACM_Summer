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
#define lc (p<<1)  //*2
#define rc (p<<1|1)	//*2+1
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
const int N=100;
int num[15][15];
int main(){
	int n;
	while(~Sca(n)&&n){
		memset(num,0,sizeof(num));
		int x=1,y=1;
	 	int index=1;
	 	int flag=1;
	 	int val=0;
		while(1){
			num[x][y]=index;
			val++;
			if(val%n==0){
				flag++;
				val=1;	
			}
			if(flag%4==1) y++;
			else if(flag%4==2) x++;
			else if(flag%4==3) y--;
			else x--;
			index++;
			if(index>(n-1)*4) break;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(num[i][j]!=0) printf("%3d",num[i][j]);
				else printf("   ");
			}
			printf("\n");
		}
	}
}







