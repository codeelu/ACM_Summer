#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000+50;
const int MAXM=10000+50; 
char t[MAXN],p[MAXN];
int next[MAXM];
int lent,lenp;

void getnext()
{
    int i=0,j=-1;
    next[i]=j;
    while (i<lenp)
    {
        if (j==-1 || p[i]==p[j]) next[++i]=++j;
            else j=next[j];
    }
}

int getans()
{
    int i=0,j=0,ans=0;
    while (i<lent)
    {
        if (t[i]==p[j] || j==-1)
        {
            i++;
            j++;
        }
        else j=next[j];
        if (j==lenp)//如果匹配成功，则视作这次匹配失败，返回到上一次。 
        {
            ans++;
            j=next[j-1];
            i--;
        }
    }
    return ans;
}

int main()
{
    int kase;
    scanf("%d",&kase);
    for (int i=0;i<kase;i++)
    {
        scanf("%s%s",p,t);
        lent=strlen(t); 
        lenp=strlen(p);//注意一定要先把strlen存下来，否则会TLE！ 
        getnext();
        cout<<getans()<<endl;
    }
    return 0;
}
