#include <bits/stdc++.h> 
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0);
int cnt,cnt1;
int fa[1000010]; 
 int a[1000010];
 int b[1000010];
 int c[1000010];
 int d[1000010];
  int a1[1000010];
 int b1[1000010];
 int c1[1000010];
 int d1[1000010];
 int n;
 int m;

int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
int  merge(int x,int y){
	int fa1=get(x);
	int fa2=get(y);
	if(fa1!=fa2)
	{
		fa[fa1]=fa2;
     return 0;
	}
	return 1;

}

int main()
{
	FAST_IO;
	int t;
 cin>>n;
 while(n--)
 {
 	int flag=0;
 	cnt=0;
 	cnt1=0;
 
 	memset(a,0,sizeof(a));
 	memset(b,0,sizeof(b));
 	memset(c,0,sizeof(c));
 	memset(d,0,sizeof(d));
 		for(int i=0;i<100010;i++){
		fa[i]=i; //每条路的父节点都是自己 
		}
		
  cin>>t;
	for(int i=1;i<=t;i++){
		int aa,bb,w;
		cin>>aa>>bb>>w;
		if(w==1){
			a[i]=aa;b[i]=bb;
			cnt++;
		}
		else
		{
			c[i]=aa;
			d[i]=bb;
			cnt1++;
		}
	}


	}
	for(int i=1;i<=cnt;i++)
{
	merge(a1[i],b1[i]);
	}
	for(int i=1;i<=cnt1;i++)
{
	if(merge(c1[i],d1[i])==1){
		flag=1;
		break;
	}
	}
	 
   if(flag)
   cout<<"NO"<<endl;
   else cout<<"YES"<<endl;
}

	return 0;
}
