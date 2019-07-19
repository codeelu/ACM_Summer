#include<bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[510],b[510];
int dp[510];
int main()
{
	FAST_IO;
    int t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
           cin>>a[i];
      cin>>m; 
        for(int i=0;i<m;i++)
            cin>>b[i];
        memset(dp,0,sizeof(dp));
        int ans=0,k;
        for(int i=0;i<n;i++)
        {
             k=0;
             for(int j=0;j<m;j++)
             {
                  if(b[j]<a[i]&&dp[j]+1>dp[k])
                    k=j;
                  if(b[j]==a[i]&&dp[j]<dp[k]+1)
                    dp[j]=dp[k]+1;
             }
        }
        for(int i=0;i<m;i++)
        {
            if(ans<dp[i])
                ans=dp[i];
        }
       cout<<ans<<endl;
        if(t) cout<<endl;
         

    }
    return 0;
}
