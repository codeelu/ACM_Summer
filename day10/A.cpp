#include <bits/stdc++.h>
typedef long long ll;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
#define next Next
typedef unsigned long long ull;
typedef long long ll;
const int maxn=1e6+10;
int n, m;
int next[maxn];
int a[maxn], b[maxn];
int lent,lenp;
void getNEXT()
{
    int i=0,j=-1;
    next[i]=j;
    while (i<m)
    {
        if (j==-1 || b[i]==b[j]) 
		   next[++i]=++j;
        else j=next[j];
    }
}

int kmp1()
{
    int i=0,j=0,ans=0;
    while (i<n)
    {
        if (a[i]==b[j] || j==-1)
        {
            i++;
            j++;
        }
        else j=next[j];
        if (j==m)  
        {
            return i-j+1;
           
        }
    }
    return -1;
}
int main()
{
	FAST_IO;
    int t; 
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++) 
		 cin>>a[i];
        for(int i=0; i<m; i++) 
		 cin>>b[i];
		 getNEXT();
		 cout<<kmp1()<<endl;
    }
    return 0;
}
