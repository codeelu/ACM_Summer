#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;  typedef long long ll;
inline int qr(){
      register int ret=0,f=0;
      register char c=getchar();
      while(c<48||c>57)f|=c==45,c=getchar();
      while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
      return f?-ret:ret;
}
const int maxn=505;
int A[maxn],B[maxn],last[maxn][maxn],dp[maxn][maxn],stk[maxn];

int main(){

      register int T=qr();
      while(T--){
        memset(last,-1,sizeof last);
        memset(dp,0,sizeof dp);
        memset(stk,0,sizeof(stk));
        register int n,m,ans=0;
        n=qr();
        for(register int t=1;t<=n;++t)
          A[t]=qr();
        m=qr();
        for(register int t=1;t<=m;++t)
          B[t]=qr();
        A[0]=B[0]=1<<31;
        for(register int t=0;t<=n;++t)
          dp[t][0]=0;
        for(register int t=1,fr=0;t<=n;++t){
          dp[0][fr=0]=0;
          for(register int i=1;i<=m;++i){
            dp[t][i]=dp[t-1][i];
            if(A[t]==B[i]){
                  if(dp[t][i]<dp[t-1][fr]+1)
                    dp[t][i]=dp[t-1][fr]+1,last[t][i]=fr;
                  //cout<<dp[t][i]<<' '<<t<<' '<<i<<' '<<fr<<' '<<last[t][i]<<endl;
            }
            if(B[i]<A[t])if(dp[t-1][fr]<dp[t-1][i])fr=i;
          }
        }
        for(register int t=1;t<=m;++t)
          if(dp[n][ans]<dp[n][t])
            ans=t;
        printf("%d\n",dp[n][ans]);
        //      continue;
        if(dp[n][ans]<=0) continue;
        int tmp_i=ans;
        for(int i=n;i>=1;--i)if(last[i][tmp_i]!=-1)stk[++stk[0]]=A[i],tmp_i=last[i][tmp_i];
        for(register int t=stk[0];t>=2;--t)
          printf("%d ",stk[t]);
        printf("%d \n",stk[1]);
      }
      return 0;
}
