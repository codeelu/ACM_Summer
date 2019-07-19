#include <bits/stdc++.h>
using namespace std;
struct node{
	int value;
	int pre;
	int next;
}a[200010];
struct order{
	int v,idx;
	bool operator < (const order & p) const {
		return v<p.v;
	} //按照从小到大排序
	order(const int x=0,const int y=0):v(x),idx(y){} 
};
 set<order>st;
int cnt=0,head=0,tail=1;
void init(){
	a[cnt].pre=-1;
	a[cnt].next=1;
	cnt=0;
}
void remove(int p)
{
	cnt--;
	a[a[p].pre].next=a[p].next;
	a[a[p].next].pre=a[p].pre;
}
 int main()
{
	int n,k;
	cin>>n>>k;
	init();
	int temp;
	for(int i=1;i<=n;i++)
	{
		++cnt;
		cin>>a[i].value;
		st.insert(order(a[i].value,i)); //能不能不写order
		a[i].pre=i-1;
		a[i].next=i+1;
		tail=i+1;
	}
	int f=1;
	while(cnt>0)
	{
		int t=0;
		auto maxx=st.rbegin(); //r? 最后一个 
		t=maxx->idx;
	
		temp=t;
		int pp=k;
		while(pp--)
		{
			if(a[temp].pre==head)
			{
				break;
			} 
		temp=a[temp].pre;
		st.erase(order(a[temp].value,temp));
		a[temp].value=f;
		remove(temp);
		}
     temp=t;
      pp=k;
	 while(pp--)
	 {
	 	if(a[temp].next==tail)
	 	break;
	 	temp=a[temp].next;
	 	st.erase(order(a[temp].value,temp));
	 	a[temp].value=f;
	 	remove(temp);
	 }
      st.erase(order(a[t].value,t));
	 a[t].value=f;
	 remove(t);
	 if(f==1) f++; 
	 else f=1;
	
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].value;
	}
	cout<<endl;
}
