#include<bits/stdc++.h>
using namespace std;
int ver[505],nxt[505],head[505],a[505],deg[505],b[505];
int tot,cnt;
int n,m;
int num=0;
void add(int x,int y){
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
	deg[y]++;
}
void topsort(){

	queue<int>q;
	for(int i=1;i<=n;i++)
	    if(deg[i]==0) {
	    	q.push(i);
	   
		}

	while(q.size()){
		int x=q.front();
		q.pop();
		a[++cnt]=x;
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			if(--deg[y]==0) {
				q.push(y);
			}
			
		}
		
	}
} 
int main(){
//	for(int i=0;i<504;i++)
//	{
//		deg[i]=1;
//	}
	while(cin >> n >> m){
		tot=cnt=0;
		memset(ver,0,505);
		memset(nxt,0,505);
		memset(head,0,505);
		memset(deg,0,505);
		memset(a,0,505);
		for(int i=1;i<=m;i++){
			int x,y;
			cin >> x >> y;
			add(x,y);
		}
		topsort();
		for(int i=1;i<=cnt;i++){
			cout << a[i] << " "; 
		}
		cout << endl;
	}
	
	
	return 0;
}
