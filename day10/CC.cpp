#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define next Next
using namespace std;
const int maxn=1e3+5;
const int maxm=1e3+5; 
string t,p;
int next[maxm];
int lent,lenp;

void getNEXT()
{
    int i=0,j=-1;
    next[i]=j;
    while (i<lenp)
    {
        if (j==-1 || p[i]==p[j]) 
		   next[++i]=++j;
         else j=next[j];
    }
}

int kmp1()
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
        if (j==lenp)  
        {
            ans++;
            j=0;
        }
    }
    return ans;
}

int main()
{
	FAST_IO;
   while(cin>>t && t[0]!='#')
    {
    	memset(next,0,sizeof(next));
        cin>>p;
        lent=t.size(); 
        lenp=p.size(); 
        getNEXT();
        cout<<kmp1()<<endl;
        
    }
    return 0;
}
