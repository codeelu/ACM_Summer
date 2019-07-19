#include <bits/stdc++.h> 
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0);
int fa[500010]; 
 int a[500010];
int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
 int num[500010];
int main()
{
	FAST_IO;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i; //每条路的父节点都是自己 
		}
	while(m--)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		cin>>a[i];
		for(int i=1;i<k;i++){
			merge(a[i],a[i+1]);
		}

		}
		for(int i=1;i<=n;i++){
			++num[get(i)];
		}
	for(int i=1;i<=n;i++){
		if(i==n)
			cout<<num[get(i)]<<endl;
		else cout<<num[get(i)]<<' ';
		}

	return 0;
}
