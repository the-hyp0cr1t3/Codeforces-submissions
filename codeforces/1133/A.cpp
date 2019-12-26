#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main() {
    IOS;
    int i, n;
    int a, b, x;
    string s, t;
    cin >> s >> t;
    stringstream ss;
    ss << s.substr(0, 2);
    ss >> x;
    a = 60*x;
    ss.clear();
    ss << s.substr(3, 2);
    ss >> x;
    a += x;
    ss.clear();
    ss << t.substr(0, 2);
    ss >> x;
    b = 60*x;
    ss.clear();
    ss << t.substr(3, 2);
    ss >> x;
    b += x;
    x = (b+a)/2;
    if (x/60 < 10) cout << 0;
    cout << x/60 << ":";
    if (x%60 < 10) cout << 0;
    cout << x%60;
    return 0;
}