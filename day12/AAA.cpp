#include<bits/stdc++.h>
using namespace std;
string rem,s;
int pos=0,maxright=0,maxlen=0,r[210000]={0};
int Manacher(){
	s.clear();
	pos=0;
	maxright=0;
	maxlen=0;
	memset(r,0,sizeof(r));
    for (int i=0; i<rem.length(); i++){
        s+='#';
        s+=rem[i];
    }
    s+='#';
    for (int i=0; i<s.length(); i++){
        if (i<maxright)
            r[i]=min(r[2*pos-i],maxright-i);
        else r[i]=1;
        while (i-r[i]>=0 && i+r[i]<s.length() && s[i-r[i]]==s[i+r[i]])
            r[i]++;
        if (r[i]+i-1>maxright){
            maxright=r[i]+i-1;
            pos=i;
        }
            maxlen=max(maxlen,r[i]);
    }
    return maxlen-1;
}
int main(){
	while(cin>>rem){
	cout<<Manacher()<<endl;
//	cin.clear();
	}
	return 0;
}
