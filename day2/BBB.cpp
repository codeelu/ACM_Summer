#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
vector<int> e[maxn];
int vis[maxn];
long long even,odd;
void dfs(int v,long long  step)
{

	if(vis[v]==1) return ;
	vis[v]=1;
	if(step%2==0) even++;
	else odd++;
    for(int i=0;i<e[v].size();i++){
		dfs(e[v][i],step+1);
	}
}
int main(){
  	int n;
  	cin>>n;
  	for(int i=1;i<n;i++)
  	{
  		int ee,v;
  		cin>>ee>>v;
  		e[ee].push_back(v);
  		e[v].push_back(ee);
  		
	}
	dfs(1,0);
	cout<<even*odd-n+1<<endl;
}
