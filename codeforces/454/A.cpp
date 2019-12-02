#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

int32_t main() {
    IOS;
    int i, n, j;
    cin >> n;
    vector<string> s(n/2 + 1, string(n, '*'));
    for(i = 0; i < n/2 + 1; i++) 
        for(j = n/2 - i; j <= n/2 + i; j++) 
            s[i][j] = 'D';
    for (auto& x: s) 
        cout << x << endl;
    for(i = n/2-1; i >= 0; i--) 
        cout << s[i] << endl;
    return 0;
}