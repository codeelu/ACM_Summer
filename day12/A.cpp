#include<bits/stdc++.h>
using namespace std;
string rem,s;
int pos=0,maxright=0,maxlen=0,r[5000005]={0};
int main(){
    cin>>rem;
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
    cout<<maxlen-1;
    return 0;
}
