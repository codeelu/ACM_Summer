#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N  = 1e5 + 5;  
typedef long long ll;
ll sum[N<<2];
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
void PushUP(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
 
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    PushUP(rt);
}
void update(int L,int R,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=sqrt(sum[rt]);
        return ;
    }
    if(L<=l&&R>=r&&sum[rt]==r-l+1)
        return;
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,l,m,rt<<1);
    if(m<R)
        update(L,R,m+1,r,rt<<1|1);
    PushUP(rt);
}
ll querySUM(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    ll ret=0;
    if(L<=m)
        ret+=(ret,querySUM(L,R,l,m,rt<<1));
    if(R>m)
        ret+=(ret,querySUM(L,R,m+1,r,rt<<1|1));
    return ret;
}
int main()
{
    int n,m;
    int Case=0;
    while(cin>>n)
    {
        int a,b,c;
        build(1,n,1);
        m=read();
        printf("Case #%d:\n",++Case);
        while(m--)
        {
        	int x,y,t;
            t=read(),x=read(),y=read();
            if(t==0)
            	update(x,y,1,n,1);
            else
                printf("%lld\n",querySUM(x,y,1,n,1));
        }
        printf("\n");
    }
    return 0;
}

