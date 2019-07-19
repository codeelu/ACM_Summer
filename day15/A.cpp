#include<bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int  a[510],b[510];  
int dp[510];    
int LCS(int n, int m)
{
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        int tmp1 = 0; // 存 i 确定, 且 a[i] > b[j] 时最大的 dp[j]
        for(int j = 1; j <= m; j++)
        {
            if(a[i] > b[j] && dp[j] > tmp1)
                tmp1 = dp[j];
            else if(a[i] == b[j])
                dp[j] = tmp1+1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++)
        ans = max(ans, dp[i]);
    return ans;
}
int main()  
{  
    FAST_IO;
    int i,j;  
    int t;
    cin>>t;
    int n,m;
    while(t--){
    		memset(dp,0,sizeof(dp)); 
    		memset(a,0,sizeof(a));
    		memset(b,0,sizeof(b));
    	cin>>n;
    	for(int i=1;i<=n;i++) cin>>a[i];
    	cin>>m;
    	for(int i=1;i<=m;i++) cin>>b[i];
       cout<<LCS(n,m)<<endl;
       
        //cout<<1<<endl;
         // cout<<dp[n][m]<<endl;
          if(t) cout<<endl;
	}
    
      
      
    return 0;  
}




