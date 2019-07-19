#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define repd(x, r, l) for(int x = r; x >= l; x--)
#define clr(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define MAXN 105
#define MAXM 40005
#define fi first
#define se second
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int p = 10000007;
int lowbit(int x){ return x & -x; }

//int fast_power(int a, int b){ int x; for(x = 1; b; b >>= 1){ if(b & 1) x = 1ll * x * a % p; a = 1ll * a * a % p; } return x; }

const int dic[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int n, m, cnt;
int head[MAXN * MAXN], nxt[MAXM], to[MAXM];
int match[MAXN * MAXN];
bool g[MAXN][MAXN], vis[MAXN * MAXN];

void init(){
    cnt = 0;
    clr(head, -1);
    clr(match, 0);
}



void add(int u, int v){
    nxt[cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    cnt++;
}

bool dfs(int u){
    for(int e = head[u]; e != -1; e = nxt[e]){
        int v = to[e];
        if(vis[v]) continue;
        vis[v] = 1;
        if(!match[v] || dfs(match[v])){
            match[v] =  u;
            return 1;
        }
    }
    return 0;
}

int main(){
    init();
    scanf("%d%d", &n, &m);
    rep(i, 1, m){
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
    }
    rep(i, 1, n)
        rep(j, 1, n)
            if(!g[i][j])
                rep(k, 0, 3){
                    int x = i + dic[k][0], y = j + dic[k][1];
                    if(x > 0 && y > 0 && x <= n && y <= n && !g[x][y] && (x + y) % 2){
                        add(id(i, j), id(x, y));
                    }
                }
																	
//																		    int id(int x, int y){
//																		    return (x - 1) * n + y;
//																		      }
    int ans = 0;
    rep(i, 1, id(n, n)){
        clr(vis, 0);
        if(dfs(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
