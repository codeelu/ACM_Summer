#include <bits/stdc++.h>
using namespace std;
 
string a;
 
int main() {
    a = "01234567891011121314151617181920";
    int i = 5;
    int j = 10;
    cout << a.substr(0,i) << ' '<< string(1,a[j]) << ' '
            << a.substr(i,j-i) << ' '<< a.substr(j+1) << endl;
}
//string(1,a[j])
