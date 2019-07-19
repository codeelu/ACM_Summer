#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<list>
#define ll long long
#define Sca(a) scanf("%d",&a)
#define Scal(a) scanf("%ld",&a)
#define Scall(a) scanf("%lld",&a)
#define Pri(a) printf("%d",a)
#define Pril(a) printf("%ld",a)
#define Prill(a) printf("%lld",a)
#define FAST_IO ios::sync_with_stdio(false)
using namespace std;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
using namespace std;

const int MAX  = 1e5+5;
int vis[MAX];
bool beaty(int x)
{
	int h[10];
	memset(h,0,sizeof(h));
	int n;
	while(x)
	{
		if(!h[x%10])h[x%10]++;
		else return false;
		x/=10;		
	}
	return true;
}
void init()
{
	for(int i=1;i<MAX;i++)
	{
		if(beaty(i))
			vis[i]=1; 
	}
}
int main()
{
	int T;
	cin>>T;
	init();
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=a;i<=b;i++)
			ans+=vis[i];
		cout<<ans<<endl;
	}
}
