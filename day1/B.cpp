#include <bits/stdc++.h>
using namespace std;
int a[2010];
int main()
{
	int m;
	int maxx=0;
	int num=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	m=1;
		for(int i=1;i<=n;i++)
	  { 
	  num=0;
		m=i;
		while(a[m]!=-1)
		{
			num++;
			m=a[m];
		}
		maxx=max(num,maxx);
	}
 cout<<maxx+1<<endl;
}
