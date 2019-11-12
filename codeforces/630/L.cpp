#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int i, j, n = 0;
    char c[5];
    cin >> c[0] >> c[4]>> c[1]>> c[3]>> c[2];
    for(j = 4, i = 1; j >= 0; i*=10, j--) 
        n += (c[j]-'0')*i;
    int k = n;
    for(i = 1; i <= 4; i++)
        n = (n*k) % 100000;
    stringstream ss;
    ss << n;
    string s;
    ss >> s;
    for(i = 0; i < (5 - (int)s.length()); i++) 
        cout << 0;
    cout << s;
    return 0;
}
