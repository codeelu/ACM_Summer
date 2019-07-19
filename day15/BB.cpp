#include <iostream>
#include <algorithm>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define MAX 150000+10

int p[MAX],n;
bool f;

int main()
{
	FAST_IO;
    int i,sum;
    cin>>n;
    for(i=1;i<=n;i++) cin>>p[i];
    f=true;
    sum=0;
    for(i=1;i<=n;i++)
    {
        if(f)
        {
            while(i<n && p[i]<=p[i+1]) i++;
            sum+=p[i];
            f=0;
        }
        else
        {
            while(i<n && p[i]>=p[i+1]) i++;
            if(i<n) sum-=p[i];
            f=1;
        }
    }
    cout<<sum<<endl;
    return 0;
}
