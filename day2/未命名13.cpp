#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100005];
int vis[100005];
long long js=1,os=0;
void dfs(int x,int step){
	for(int i=0;i<vec[x].size();i++){
		if(vis[vec[x][i]]==0){
			vis[vec[x][i]]=1;
			if(step%2==1) js++;
			else os++;
			dfs(vec[x][i],step+1);
		}
	}
}
int main(){
	int n;
	cin >> n;
	int a,b;
	for(int i=1;i<n;i++){
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	vis[1]=1;
	dfs(1,0);
	cout << js*os-n+1 << endl;
	return 0;
}
