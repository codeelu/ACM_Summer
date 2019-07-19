#include <bits/stdc++.h>
using namespace std;
int main()
{
	//Floyd-Warshall算法核心语句
	for(k=1;k<=n;k++) //n是顶点式
	 for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	   if(e[i][j]>e[i][k]+e[k][j])  //k是中转站 
	     e[i][j]=e[i][k]+e[k][j];
		
	return 0;
	   
 } 
