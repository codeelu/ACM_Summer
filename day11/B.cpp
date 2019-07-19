#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define end End
const int maxn = 300005;
int n;
string s;
int p;
bool end[maxn];
int cnt[maxn][30];
int trie[maxn][30],tot=1;
void insert(string str){
	int len=str.size();
	p=1;
	for(int k=0;k<len;k++){
		int ch=str[k]-'a';
		
		if(trie[p][ch]==0) {
			trie[p][ch]=++tot;
			cnt[p][ch]=1;
			p=trie[p][ch];
		}
		
	}
	end[p]=true;
}
int search(string str){
	int len=str.size();
	p=1;
	int k;
	for(k=0;k<len;k++){
		p=trie[p][str[k]-'a'];
		if(p==0)  {return 0;	}
	}
	if(end[p]) return 1;
	else return cnt[p][str[--k]-'a']+1;
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
