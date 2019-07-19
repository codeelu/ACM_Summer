//Bellman-Ford
//SPFA
#include <iostream> 
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 100010;
int dis[MAX], vis[MAX] ,head[MAX];
int n, m, s, t, cnt;
struct edge
{
	int v, w, next;
}edge[1000010];
 
void add(int u, int v, int w)
{
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
 
void spfa(int s)
{
	int pos, v;
	queue<int> q;
	q.push(s);
	dis[s] = 0; vis[s] = 1;
	while(!q.empty())
	{
		pos = q.front(); q.pop();
		vis[pos] = 0;
		for(int i = head[pos]; i ; i = edge[i].next)
		{
			v = edge[i].v;
			if(dis[pos] + edge[i].w < dis[v]) //
			{
				dis[v] = dis[pos] + edge[i].w;
				if(!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}
 
int main() 
{
    cin>>n>>m>>s>>t;
		cnt = 0;
		memset(head, 0, sizeof(head));
		memset(vis, 0, sizeof(vis));
		memset(dis,0x3f, sizeof(dis));//0x37
		while(m--)
		{
			int x, y, w;
			cin>>x>>y>>w;
			add(x, y, w);
			add(y, x, w);
		}
		spfa(s);
	cout<<dis[t]<<endl;
	
	return 0;
}


