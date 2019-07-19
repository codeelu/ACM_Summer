#include <bits/stdc++.h>
using namespace std;       
#define ll long long       
const ll INF = 0x3f3f3f3f; 
const ll N   = 5e4 + 5;    
const ll MOD = 1e9 + 7;   
ll read() {
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
  struct Tree {
    int l, r;
    ll  sum, lz, max, min;
    void update(ll v) {
      sum += v * (r - l + 1); //总和 
      lz  += v;
      max += v;
      min += v;
    }
  } tree[N * 4];

  void modify(ll *arr) { //??? 
    a = arr;
  }

  void pushup(int x) {
    tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
    tree[x].max = max(tree[2 * x].max, tree[2 * x + 1].max);
    tree[x].min = min(tree[2 * x].min, tree[2 * x + 1].min);
  }

  void pushdown(int x) {
    if (tree[x].lz != 0) {
      tree[2 * x].update(tree[x].lz);
      tree[2 * x + 1].update(tree[x].lz);
      tree[x].lz = 0;
    }
  }

  void build(int x, int l, int r) {
    tree[x].l   = l;
    tree[x].r   = r;
    tree[x].sum = tree[x].max = tree[x].min = tree[x].lz = 0;

    if (l == r) {
      tree[x].sum = tree[x].max = tree[x].min = a[l];

      return;
    }
    int mid = (l + r) / 2;
    build(2 * x,     l,       mid);
    build(2 * x + 1, mid + 1, r);
    pushup(x);
  }
 //区间L~R加c 
  void updateADD(int x, int l, int r, ll c) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;

    if ((l <= L) && (r >= R)) {
      tree[x].update(c);
      return;
    }

    pushdown(x);

    if (l <= mid) updateADD(2 * x, l, r, c);

    if (r > mid) updateADD(2 * x + 1, l, r, c);
    pushup(x);
  }
 //查询区间L~R的和 
  ll querySUM(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    ll  res = 0;

    if ((l <= L) && (r >= R)) { // 要更新区间包括了该区间
      return tree[x].sum;
    }

    pushdown(x);

    if (l <= mid) res += querySUM(2 * x, l, r);

    if (r > mid) res += querySUM(2 * x + 1, l, r);
    pushup(x);
    return res;
  }
} tree;

ll   n, a[N], l, r, v, CASE;
char s[10];
ll   ans;

int main() {
  CASE = 0;
//  for (int _ = read(); _; _--) {
//    n = read();
 int t;
 scanf("%d",&t);
 while(t--){
 	CASE++;
 scanf("%d",&n);
    for (int i = 1; i <= n; i++)  a[i] = read();//scanf("%d",&a[i]); //
    tree.modify(a);
    tree.build(1, 1, n);
    printf("Case %d:\n", CASE++);

    while (~scanf("%s", s)) {
      if (s[0] == 'E') break;
      else if (s[0] == 'A') {
      	//scanf("%d",&l);scanf("%d",&v);
        l = read(), v = read();
        tree.updateADD(1, l, l, v);
      }
      else if (s[0] == 'S') {
      	//scanf("%d",&l);scanf("%d",&v);
        l = read(), v = read();
        tree.updateADD(1, l, l, -v);
      }
      else {
      //	scanf("%d",&l);scanf("%d",&v);
        l   = read(), r = read();
        ans = tree.querySUM(1, l, r);
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}

