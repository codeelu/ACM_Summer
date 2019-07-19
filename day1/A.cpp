#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a<b;
}
int flag=0;
int x,y;
int du[100010];
int main()
{
	int n,m;
	cin>>n>>m;
	int k;
	 for(int i=1;i<=m;i++)
	 {
	     cin>>x>>y;
	     ++du[x];
	     ++du[y]; 
	 }
 for(int i=1;i<=n;i++)
 {
 	if(du[i]==1) a1++;
 	if(du[i]==2) b1++;
  } 
  if(a1==2) cout<< "bus topology"<<endl;
  else if(b1==2*n) cout<<"ring topology"<<endl;
  else if(a1=n-1 1) cout<<"star topology"<<endl;
  else cout<<"unknown topology"<<endl;
  
} 
