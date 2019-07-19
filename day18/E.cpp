#include <bits/stdc++.h>
using namespace std;         
typedef long long ll;    
const ll INF = 0x3f3f3f3f; 
const ll N   = 1e5 + 5;    
const ll MOD = 1e9 + 7;    
ll sum[N<<2];
ll a[N];
int read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1; ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0'; ch = getchar();
  }
  return x * f;
}

 struct segt {
  ll *a;
  ll  SUM, MAX, MIN;
  struct Tree {
    int l, r;
    ll  sum, lz, max, min, set;
    void update(ll v) {
      sum += v * (r - l + 1);
      lz  += v;
      max += v;
      min += v;
    }

    void setval(ll v) {
      sum = v * (r - l + 1);
      lz  = 0;
      max = v;
      min = v;
      set = v;
    }
  } tree[N * 4];

  void modify(ll *arr) {
    a = arr;
  }

  void pushup(int x) {
    tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
    //tree[x].max = max(tree[2 * x].max, tree[2 * x + 1].max);
    //tree[x].min = min(tree[2 * x].min, tree[2 * x + 1].min);
  }

  void pushdown(int x) {
    if (tree[x].set != -1) {
      tree[2 * x].setval(tree[x].set);
      tree[2 * x + 1].setval(tree[x].set);
      tree[x].set = -1;
    }

    if (tree[x].lz != 0) {
      tree[2 * x].update(tree[x].lz);
      tree[2 * x + 1].update(tree[x].lz);
      tree[x].lz = 0;
    }
  }

  // 建树
  void build(int x, int l, int r) {
    tree[x].l   = l;
    tree[x].r   = r;
    tree[x].sum = tree[x].max = tree[x].min = tree[x].lz = 0;
    tree[x].set = -1;

    if (l == r) {
      return;
    }
    int mid = (l + r) / 2;
    build(2 * x,     l,       mid);
    build(2 * x + 1, mid + 1, r);
    pushup(x);
  }
void update(int L,int R,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=sqrt(sum[rt]);
        return ;
    }
    if(L<=l&&R>=r&&sum[rt]==r-l+1)//如果区间内的所有数都是1则不必更新
        return;
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,l,m,rt<<1);
    if(m<R)
        update(L,R,m+1,r,rt<<1|1);
    pushup(rt);
}


  
ll querySUM(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    ll ret=0;
    if(L<=m)
        ret+=(ret,querySUM(L,R,l,m,rt<<1));
    if(R>m)
        ret+=(ret,querySUM(L,R,m+1,r,rt<<1|1));
    return ret;
}



} tree;
int main(){
	int n;
	int Case=0;
	while(cin>>n){
		for(int i=1;i<=n;i++) a[i]=read();
	tree.modify(a);
	tree.build(1, 1, n);
	int m;
		m=read();
		printf("Case #%d:\n",++Case);
		while(m--){
			int t,x,y;
			cin>>t>>x>>y;
			if(t==0){
				tree.update(x,y,1,n,1);
				cout<<"t=0"<<endl;
			}
			else
			 	printf("%lld\n",tree.querySUM(x,y,1,n,1));
		}
		printf("\n");
	}
}





































