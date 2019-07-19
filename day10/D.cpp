#include <bits/stdc++.h> 
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define next Next
using namespace std;
string str;
const int maxn =100005;
int len, next[maxn];

void getNext()
{
	int i = 0, j = -1;
	next[i]=j;
	while(str[i]){
		if(j == -1 || str[i] == str[j])
		  next[++i]=++j;
		else j = next[j];
	}
	len = i; 
}

int main()
{
	FAST_IO;
	int n, ans;
	cin>>n;
	while(n--){
	cin>>str;
		getNext();
		ans = len - next[len];
		if(ans != len && len % ans == 0)
			ans = 0;
		else ans = ans - next[len] % ans;
		cout<<ans<<endl;
	}
	
	return 0;
}
