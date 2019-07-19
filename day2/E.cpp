#include <bits/stdc++.h>
using namespace std;
int ans[510],num=0;
int a[510][510];
int b[510];
int k;
int main()
{
  	int n,m;
  	while(cin>>n>>m)
  	{
  		memset(ans,0,sizeof(ans));
  		memset(a,0,sizeof(a));
  		memset(b,0,sizeof(b));
  		num=0;
  			int a1,a2;
  		for(int i=0;i<m;i++)
		  {
		  	 cin>>a1>>a2;
		  	if(a[a1][a2]==0){
		  		a[a1][a2]=1;
		  		b[a2]++;
			  } 
		  	 
		  } 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if (b[j]==0){
					k=j;
				
					break;
				} 
			}
				b[k]=-1;
			ans[++num]=k;
			
		  for(int u=1;u<=n;u++)
		  {
		  	if(a[k][u]!=0)
		  	  b[u]--;
		  }
		}
//		cout<<ans[0]<<endl;
		for(int i=1;i<=n;i++)
		{
			if(i!=1) cout<<" ";
			 cout<<ans[i]; 
		}
		cout<<endl;
	}

} 
