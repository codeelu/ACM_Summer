#include <bits/stdc++.h>
using namespace std;
int flag=-1;
struct Node{
	int value;
	int prev,next;
}node[100010];
struct Node1{
	int value;
	int prev,next;
}node1[100010];
bool cmp(Node1 a,Node1 b)
{
	return a.value>b.value;
}
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
  int insert1(int p,int val){
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
  	
  	if(flag==1)
  	  pp=1;
   else
      pp=2;
  
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
     	cin>>node1[i].value;
     	insert(i,node1[i].value);
           node1[value].idx=i;
     	
     
	 }
	 int index;

	 int kk=0;
	 int a1=maxx,b1=0;
	 int yu=0;
	 while(yu<n)
	 {
	 	node1=node;
		 sort(node1+1,node1+1+n,cmp);
		 cout<<node1[1].value<<"@"<<endl;
	     index=node1[1].idx;  
	    
	          //等会给他清空为-1 
     int aa=index-k; if(aa<=0) aa=1; 
	  cout<<aa<<"endl"<<endl;
     int bb=index+k;   if(bb>n) bb=n;
     cout<<bb<<"endl "<<endl;
     flag=-flag;
     
      
      
      for(int i=aa;i<=bb;i++)
     {
       remove(i);
       yu++;
       
       node1[node1[1].value].value=-1; 
      }
      
	}
	
	 for(int i=1;i<=n;i++)
	 {
	 	cout<<b[i];
	 }
  }
