//trieÊ÷Ä£°å 
#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
const int maxn = 200005;
int n;
string s;
bool end[maxn];
int trie[30][30],tot=1;
void insert(string str){
	int len=str.size();
	p=1;
	for(int k=0;k<len;k++){
		int ch=str[k]-'a';
		if(trie[p][ch]==0) {
			trie[p][ch]=++tot;
		}
		p=trie[p][ch];
	}
	end[p]=true;
}
bool search(string str){
	int len=str.size();
	p=1;
	for(int k=0;k<len;k++){
		p=trie[p][str[k]-'a'];
		if(p==0) return false;
	}
	return end[p];
}
int main(){
	return 0;
}
