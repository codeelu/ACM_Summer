#include<bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int dp[25][25];
int a[25];

int dfs(int pos,int pre,int sta,int limit)
{
    if(pos == -1)return 1;
    if(!limit&&dp[pos][sta]!=-1)
        return dp[pos][sta];
    int up = limit?a[pos]:9;
    int tem = 0;
    for(int i = 0;i<=up;i++)
    {
        if(pre == 6&&i == 2)continue;
        if(i == 4)continue;
        tem+=dfs(pos-1,i,i == 6,limit &&i == a[pos]);
    }
    if(!limit)dp[pos][sta] = tem;
    return tem;
 
}
 
int find(int x)
{
    int pos = 0;
    while(x){
        a[pos++] = x%10;
        x/=10;
    }
    return dfs(pos-1,-1,0,true);
}
int main()
{
	FAST_IO;
    int a,b;
    memset(dp,-1,sizeof(dp));
    while(cin>>a>>b)
    {
    	if(a==0 && b==0) break;
    	cout<<find(b)-find(a-1)<<endl;;
    }
    return 0;
}

