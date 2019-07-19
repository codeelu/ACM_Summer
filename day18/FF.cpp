#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxn=100009;
int n,cover[maxn<<2],color[maxn<<2];//cover标记此区间是否是同一种颜色，color表示此区间的颜色状态，
//由于颜色不超过30种，故可以用int的每一位来表示颜色,相比于开一个数组要方便得多
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
int temp;
int L,T,t;

void pushup(int rt)
{
  color[rt]=color[rt<<1]|color[rt<<1|1];
}
void pushdown(int rt)
{
    if(cover[rt])
    {
        cover[rt<<1]=cover[rt<<1|1]=cover[rt];
        color[rt<<1]=color[rt<<1|1]=color[rt];
        cover[rt]=0;
    }
}
void build(int l,int r,int rt)
{
    color[rt]=1;
    cover[rt]=1;
    if(l==r)
        return ;
    int m=l+r>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        cover[rt]=1;
        color[rt]=c;
        return;
    }
    if(color[rt]==c)//如果此时的状态和要改变的状态一样则没有必要再进行下去
        return;
    int m=l+r>>1;
    pushdown(rt);
    if(L<=m) update(L,R,c,l,m,rt<<1);
    if(R>m) update(L,R,c,m+1,r,rt<<1|1);
    pushup(rt);
}
void query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        temp|=color[rt];
        return;
    }
    if(cover[rt])
    {
        temp|=color[rt];//如果颜色一样则没有必要继续划分区间，很重要哦~
        return;
    }
    int m=l+r>>1;
    pushdown(rt);
    if(m>=L) query(L,R,l,m,rt<<1);
    if(m<R) query(L,R,m+1,r,rt<<1|1);
    pushup(rt);
}
int main()
{
   L=read(), T=read(), t=read();
    build(1,L,1);
    while(t--)
    {
        char ch[10];
        int a,c,b;
        scanf("%s",ch);
        if(ch[0]=='C')
        {
            a=read(),b=read(),c=read();
            if(a>b) swap(a,b);
            update(a,b,1<<(c-1),1,L,1);
        }
        else
        {
             a=read(),b=read();
            if(a>b) swap(a,b);
            temp=0;
            query(a,b,1,L,1);
            int sum=0;
            while(temp)
            {
                if(temp&1)
                    sum++;
                 temp>>=1;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}

