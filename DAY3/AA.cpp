#include <bits/stdc++.h> 
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0);
int cnt,cnt1;
int fa[100010]; 
 int a[100010];
 int b[100010];
  int num[100010];
int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	int fa1=get(x);
	int fa2=get(y);
	if(fa1!=fa2)
	{
		fa[fa1]=fa2;
		cnt--;
	
	}
		num[--cnt1]=cnt;

}

int main()
{
	FAST_IO;
	int n,m;
while(cin>>n>>m){
	cnt=n;
	cnt1=m;
	num[m]=n;
	
	for(int i=0;i<n;i++){
		fa[i]=i; //每条路的父节点都是自己 
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b)); 
  for(int j=1;j<=m;j++)
	{
		cin>>a[j]>>b[j];
	}
		for(int i=m;i>0;i--){
			merge(a[i],b[i]);
		}

		
	for(int i=1;i<=m;i++){
	
			cout<<num[i]<<endl;
	}
}

	return 0;
}
