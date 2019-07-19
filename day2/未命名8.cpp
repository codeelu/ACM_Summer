#include<bits/stdc++.h>
using namespace std;
int ver[505],nxt[505],head[505],deg[505],a[505];
int tot,cnt;
int n,m;
void add(int x,int y){
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
	deg[y]++;
}
void topsort(){
	queue<int>q;
	for(int i=1;i<=n;i++)
	    if(deg[i]==0) q.push(i);
	while(q.size()){
		int x=q.front();
		q.pop();
		a[++cnt]=x;
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			if(--deg[y]==0) q.push(y);
		}
		
	}
} 
int main(){
	int num;
	cin>>num;
	int tt;
	while(num--)
	
               {
               	cin>>n>>m>>tt;
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
		if(cnt<n) cout<<"NO"<<endl;
		else cout << "YES"<<endl;
	}
	
	
	return 0;
}
