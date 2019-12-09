#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define all(a) a.begin(),a.end()
#define pb push_back

int32_t main() {
    IOS;
    int i, j, n, a = 0, b = 0, s, c;
    cin >> n;
    vector<int> v; 
    for(i = 0; i < n; i++) {
        cin >> s;
        for(j = 0; j < s; j++) {
            cin >> c;
            if (s&1 and j == s/2)
                v.pb(c);
            else if (j < s/2)
                a += c;
            else
                b += c;
        }
    }
    sort(all(v), greater<int>());
    i = 1;
    int p = a, q = b;
    for (auto& x: v) {
        if (i)
            a += x, q += x;
        else
            b += x, p += x;
        i ^= 1;
    }
    cout << a << " " << b;
    return 0;
}