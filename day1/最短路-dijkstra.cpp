for(int i=1;i<=n;i++)//n是顶点数
  dis[i]=e[1][i];    //dis[i]表示1顶点到i的最短距离
for(int i=1;i<=n;i++)
 book[i]=0;
 
 book[1]=1;   //该点已经被记录
 
 //Disjkstra算法核心语句 单源最短路
 for(int i=1;i<=n-1;i++)
 {
 	min=inf;
 	for(j=1;j<=n;j++)
 	{
 		if(book[j]==0 && dis[j]<min)
 		{
 			min=dis[j];
 			u=j;
		 }
	}  
	book[u]=1;
	for(v=1;v<=n;v++)
	{
		if(e[u][v]<inf) //有路可走 
		{
			if(dis[v]>dis[u]+e[u][v])
			   dis[v]=dis[u]+e[u][v];
		}
	}
  }
  for(i=1;i<=n;i++)
   cout<<dis[i];
   
 
  
 
 
  
