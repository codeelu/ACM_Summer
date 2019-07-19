#include <bits/stdc++.h> 
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0);
int cnt,cnt1;
int fa[100010]; 
 int a[100010];
 int b[100010];
  int num[100010];
  int sum=0;
  int count1;
	int get(int x) //找父节点 
	{
		if(x==fa[x]) return x;
		return fa[x]=get(fa[x]);
	}
int  merge(int x,int y){ //合并两个节点 
	int fa1=get(x);
	int fa2=get(y);
	if(fa1!=fa2)
	{
		fa[fa1]=fa2;
		return 1;
	
	}
	return 0;

}
struct edge{
	int u;
	int v;
	int w;
}e[100010];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main()
{
	FAST_IO;
	int n,m;
	
while(cin>>n>>m){
	int flag=0;
	 sum=0;
   count1=0;
	memset(e,0,sizeof(e));
	if(n==0) break; 
	for(int i=1;i<=m;i++){
		fa[i]=i; //每条路的父节点都是自己 
		}
	
  for(int i=1;i<=n;i++)
	{
	  cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
		if(	merge(e[i].u,e[i].v))
		{
			sum+=e[i].w;
			count1++;
		}
		if(count1==m-1) 
		{
		  
		  flag=1;
		  break;
		} 
	}
       
		  if(!flag) {
  	   cout<<'?'<<endl;
         }
        else  cout<<sum<<endl;
}

	return 0;
}
