
#include<bits/stdc++.h>
#define map mapp 
using namespace std;
int vis[210];
int match[210];
int n;
int map[210][210];
int dfs(int u)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!vis[i] && map[u][i])
        {
           vis[i]=1;
            if(match[i]==-1||dfs(match[i]))
            {
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
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
        memset(match,-1,sizeof(match));
         memset(map,-1,sizeof(map));
   
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               cin>>map[i][j];
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
