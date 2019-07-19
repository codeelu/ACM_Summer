//最小表示法 
#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
const int maxn = 200005;
int n;
string s;
string a;
int minn() {
	int i = 0, j = 1;
	int k;
	while( i < n && j < n) {
	
		for( k=0; k < n && s[i + k] == s[j + k]; k++);
		if(k == n) return i;
		if(s[i + k] > s[j + k]) 
		  i = i + k + 1;
		else 
		  j = j + k + 1;
		if(i == j) j++;
	}
	return i;
}
 
int main() {
	FAST_IO;
	int t;
	cin>>t;
	while(t--) {
		s.clear() ;
		a.clear() ;
		cin>>s;
		a=s;
		n = s.size();
		for(int i = 0; i < n; i++) s.push_back(s[i]); 
		int ans =minn();
		cout<<ans+1<<endl;
	}
	return 0;
}

