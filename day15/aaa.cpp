
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,a[10010],b[10010],dp[100010],maxn;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
        {
            maxn=0;
            for(int j=0; j<m; j++)
            {
                if(a[i]>b[j]) maxn=max(dp[j],maxn);
                if(a[i]==b[j]) dp[j]=maxn+1;
            }
        }
        maxn=0;
        for(int i=0; i<m; i++)
            maxn=max(dp[i],maxn);
        printf("%d\n",maxn);
        if(t) printf("\n");
    }
}


