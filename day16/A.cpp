#include<bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[1000010];
int flag;
void init(){
	a[0]=1;
    a[1]=1;
    a[2]=2;
	for(int i=3;i<=1e6;i++){
		string s=to_string(i);
		flag=0;
		 for(int j=0;j<s.size();j++){
		 	if(s[j]=='4' || (s[j]=='6' && s[j+1]=='2')){	 
		 	flag=1;break;
		}
	}
		 if(!flag)
	      a[i]=a[i-1]+1;
	      else
	      a[i]=a[i-1];
	
	}
}
int main(){
	init();
	int n,m;
//	for(int i=1;i<=100;i++) cout<<a[i]<<endl;
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		
	 cout<<a[m]-a[n-1]<<endl;
	}
}

