//trie Ê÷ 
#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
const int maxn = 1e7+5;
int n;
string s[1005];
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
void  search(string str){
	int len=str.size();
	p=1;
	ans = 0;	
	for(int k=0;k<len;k++){
		p=trie[p][str[k]-'a'];
		ans = cnt[p];
		if(ans==1) {
	        cout<<str[k];
	        return ;
		}
		else cout<<str[k];
	}
	return ;
}
int main(){
	FAST_IO;
	int n=0;
	while(getline(cin,s[n])){
		if(s[n]=="") break;
		insert(s[n]);
		n++;
	}
	int k=0;
	while(n--){
	 cout<<s[k]<<' ';
	 search(s[k]);
	 cout<<endl;
	 k++;
	}
}
