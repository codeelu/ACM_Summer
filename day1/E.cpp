#include <bits/stdc++.h>
using namespace std;
struct Node{
	int value;
	int prev,next;
	
}node[100010];
int b[100010];
  int head,tail,tot;
  int q,pp=0;
  int initialize()
  {
  	tot=2;
  	head=1;
  	tail=2;
  	node[head].next=tail;
  	node[tail].prev=head;
  	
  }
  int insert(int p,int val){
  	q=++tot;
  	node[q].value=val;
  	node[node[q].next].prev=q;
  	node[q].next=node[p].next;
  	node[p].next=q;
  	node[q].prev=p;
  }
  void remove(int p)
  {
  	node[node[p].prev].next=node[p].next;
  	node[node[p].next].prev=node[p].prev;
  	++pp;
  	if(pp==3) pp==1;
  	b[p]=pp;
  }
  int main()
  {
     int n,k;
     cin>>n>>k;
    int val;
    int maxx=0;
     for(int i=1;i<=n;i++)
     {
     	cin>>val;
     	insert(i,val);
     	maxx=max(maxx,val);
	 }
	 int a1=maxx,b1=0;

	 while(a1 && b1<=k){
	 	 remove(a1);
	 	 --a1;
	 	 ++b1;
	 }
	 a1=maxx+1;
	 while(a1<=n && b1<=k){
	 	 remove(a1);
	 	 ++a1;
	 	 ++b1;
	 }
	 
	 for(int i=1;i<=n;i++)
	 {
	 	cout<<b[i];
	 }
  }
