//trieÊ÷ 
#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
const int maxn = 1e7+5;
int n;
string s;
int cnt[maxn];
int trie[maxn][30],tot=1;
int ans = 0;
int p;
void insert(string str){
	int len=str.size();
	p=1;
	for(int k=0;k<len;k++){
		int ch=str[k]-'a';
		if(trie[p][ch]==0) {
			trie[p][ch]=++tot;
		}
		p=trie[p][ch];
		cnt[p]++;
	}
}
int  search(string str){
	int len=str.size();
	p=1;
	ans = 0;	
	for(int k=0;k<len;k++){
		p=trie[p][str[k]-'a'];
		ans = cnt[p];
	}
	return ans;
}
int main(){
	FAST_IO;
	while(getline(cin,s)){
		if(s=="") break;
		insert(s);
	}
	
	while(cin>>s){
		cout<<search(s)<<endl;
	}
}
