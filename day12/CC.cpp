#include<bits/stdc++.h>
#include <queue>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
using namespace std;
int main()
{
	FAST_IO;
	ll m;
 priority_queue<int>q; ///优先队列 
 ll n, i,t;

 	cin>>n;
 	while(!q.empty())
 	 q.pop();
 for( i =0; i<n; i++)
{
   cin>>m;
   q.push(-m);
}
  ll sum =0 ;
while(!q.empty())
{
  ll a1 = q.top();
  q.pop();
  if(q.empty())
   break;
  ll a2 = q.top();
  q.pop();
  sum = sum -a1-a2;
  q.push( a1+a2 );
 }
  cout<<sum<<endl<<endl; 

 return 0;
}

