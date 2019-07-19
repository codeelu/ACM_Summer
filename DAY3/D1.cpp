//¿Î…¢ªØµƒÃ‚ 
#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
using namespace std;
int  const max=1e6+10;
 void init(){
 	for(int i=1;i<=m;i++)
 	fa[i]=i;
 }
 int get(int x)
 {
 	if(x==fa[x]) return x;
 	return fa[x]=get(fa[x]);
 }
 
