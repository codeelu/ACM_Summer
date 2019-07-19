#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long  n,m;
	cin>>n>>m;
	long long  a1;
	long long  minn;
	if(2*m>=n) minn=0;
	else minn=n-2*m;
	
	for(long long  i=n;i>=0;i--)
	{
		if((i*i-i) < 2*m)
		 break;
	  a1=i;
	} 
  
	cout<<minn<<' '<<n-a1<<endl; 
    system("pause");
}
