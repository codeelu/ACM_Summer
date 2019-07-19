#include <bits/stdc++.h>
using namespace std;
int f[100010];
bool vis[10];
int main(){
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=100000;i++){
		int flag=0;
		string a=to_string(i);
		for(int i=0;i<a.size();i++){
			if(vis[(a[i]-'0')]){
				flag=1;
				break;
			}
			else{
				vis[(a[i]-'0')]=1;
			}
		}
		for(int j=0;j<10;j++) vis[j]=0;
	 if(!flag)	
		f[i]=f[i-1]+1;
		else
		f[i]=f[i-1];
	}
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		int c=f[b]-f[a];
		int flag=0;
		string s=to_string(a);
		for(int i=0;i<s.size();i++){
			if(vis[(s[i]-'0')]){
				flag=1;
				break;
			}
			else{
				vis[(s[i]-'0')]=1;
			}
		}
		for(int j=0;j<10;j++) vis[j]=0;
		if( !flag)
		  c++;
		cout<<c<<endl;
	}
}
