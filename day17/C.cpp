#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;         
typedef long long ll;    
const ll INF = 0x3f3f3f3f; 
const ll N   = 5e4 + 5;    
const ll MOD = 1e9 + 7;    
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
	 int *a;
	 struct Tree {
	 int l, r;
	 int sum, lz, max, min;
	 void update(ll v) {
		 sum += v * (r - l + 1);
		 lz += v;
		 max += v;
		 min += v;
	 }
 } tree[N * 4];
 void modify(int *arr) {
 	a = arr;
 }
 void pushup(int x) {
	 //tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
	 tree[x].max = max(tree[x << 1].max, tree[x << 1 | 1].max);
	 tree[x].min = min(tree[x << 1].min, tree[x << 1 | 1].min);
 }
 void build(int x, int l, int r) {
	 tree[x].l = l;
	 tree[x].r = r;
	 tree[x].sum = tree[x].max = tree[x].min = tree[x].lz = 0;
	 if (l == r) {
		 tree[x].sum = tree[x].max = tree[x].min = a[l];
		 return;
	 }
	 int mid = (l + r) / 2;
	 build(2 * x, l, mid);
	 build(2 * x + 1, mid + 1, r);
	 pushup(x);
 }
 // ??? ?l-r ????
ll queryMAX(int x, int l, int r) {
	 int L = tree[x].l, R = tree[x].r;
	 int mid = (L + R) >> 1; 
	 ll res1 = -INF;
	 ll res2=INF;
	 if ((l <= L) && (r >= R)) { // ???????????
	 	return tree[x].max;
	 }
	
	 if (l <= mid) {
	res1 = max(res1, queryMAX(x << 1, l, r));
	res2 = min(res2, queryMAX(x << 1, l, r)); }
	 if (r > mid){
	 	res1 = max(res1, queryMAX(x << 1 | 1, l, r));
	    res2 = min(res2, queryMAX(x << 1 | 1, l, r));
	 } 
	 //pushup(x);
	 return res1-res2;
 }


// ll queryMIN(int x, int l, int r) {
//	 int L = tree[x].l, R = tree[x].r;
//	 int mid = (L + R) >> 1;
//	 ll res = INF;
//	 if ((l <= L) && (r >= R)) { 
//	 	return tree[x].min;
//	 }
//	 if (l <= mid) res = min(res, queryMIN(x << 1, l, r));
//	 if (r > mid) res = min(res, queryMIN(x << 1 | 1, l, r));
//	 //pushup(x);
//	 return res;
// }

}tree;
int a1,b;
int   n, a[N],m;
int main() {
 	n=read(),m=read();
    for (int i = 1; i <= n; i++) a[i] = read();
    tree.modify(a);
    tree.build(1, 1, n);
    while (m--) {
	    a1=read(),b=read();
		
		printf("%lld\n",tree.queryMAX(1,a1,b));
    }
     return 0;
  }
 

