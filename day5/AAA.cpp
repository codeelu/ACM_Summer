#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<list>
#define ll long long
#define Sca(a) scanf("%d",&a)
#define Scal(a) scanf("%ld",&a)
#define Scall(a) scanf("%lld",&a)
#define Pri(a) printf("%d",a)
#define Pril(a) printf("%ld",a)
#define Prill(a) printf("%lld",a)
#define FAST_IO ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
using namespace std;
template <class T>void tomax(T&a,T b) {
	a=max(a,b);
}
template <class T>void tomin(T&a,T b) {
	a=min(a,b);
}
const int N=1e5+5;
const int M=1e5+5;
int a[20],n,a1,b;
int main() {
	while(~Sca(n)) {
		a1=n*4-4;
		b=a1+n+1;
		if(n==0)
			return 0;
		if(n==1) {
			printf("  1\n");
			continue;

		}


		for(int i=1; i<=n; i++)
		    if(i>=10)
			printf(" %d",i);
			else
			printf("  %d",i);
			
			printf("\n");
		for(int j=0; j<n-1; j++) {
			if(j==n-2)
			{
				for(int i=0;i<n;i++)
				if(a1-(n-2)-i>=10)
				printf(" %d",a1-(n-2)-i);
				else
				printf("  %d",a1-(n-2)-i);
			}
			if(j==n-2)
			{
				printf("\n");
				break;
			}
		
			for(int i=1; i<=n; i++) {
				if(i==1)
				{
					if(a1-j>=10)
					printf(" %d",a1-j);
					else
					printf("  %d",a1-j);
				}
					
				else if(i==n)
				{
					if(b-a1+j>=10)
					printf(" %d",b-a1+j);
					else
					printf("  %d",b-a1+j);
				}
				else
				    printf("   ");
			}
			
			printf("\n");
		}

	}


}
