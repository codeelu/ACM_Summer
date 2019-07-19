
#include<bits/stdc++.h>
#define next Next
using namespace std;

int const maxn = 500;
int k,m,n;
int tot;
int next[maxn],ver[maxn],head[maxn],match[maxn];
bool vis[maxn];
void add(int x,int y){
	ver[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}
bool dfs(int x){
	for(int i=head[x],y;i;i=next[i]){
		y=ver[i];
		if(!vis[y]) {
			vis[y]=1;
			if(!match[y] || dfs(match[y])){
				match[y]=x;return true;
			}
		}
	}
	return false;
}
int main()
{
    int T;
    int cnt;
   cin>>T;
    while(T--)
    {
       cin>>n;
        cnt=0;
    memset(ver,0,sizeof(ver));
	memset(next,0,sizeof(next));
	memset(head,0,sizeof(head));
	memset(match,0,sizeof(match));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              int x,y;
              cin>>x>>y;
              add(x,y);
            }
        }
        for(int i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
                cnt++;
        }
        if(cnt==n)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
