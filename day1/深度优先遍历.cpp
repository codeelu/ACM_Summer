#include <bits/stdc++.h>
int min=99999999,book[101],n,e[101][101];
void dfs(int cur, int dis)
{
	int j;
	if(dis>min) return ;
	if (cur==n)
	{
		if(dis<min) min=dis;
		return ;
	}
	for(j=1;j<=n;j++)
	{
		if(e[cur][j]!=99999999 && book[j]==0)
		{
			book[j]=1;
			dfs(j,dis+e[cur][j]);
			book[j]=0;
		}
	}
	return ;
} 
int main()
{
	return 0;
 } 
//图的深度优先遍历 
