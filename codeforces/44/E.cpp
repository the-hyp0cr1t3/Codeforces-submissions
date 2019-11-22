#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define sz(x) (int)(x).size()

int32_t main() {
    IOS;
    int k, n, a, b;
    string s;
    cin >> k >> a >> b >> s;
    n = sz(s);
    if (k*a > n or k*b < n)
        return cout << "No solution", 0;
    int i = 0, j = n%k;
    while(i < n)  {
        int x = n/k + (j>0);
        cout << s.substr(i, x) << endl;
        i += x, j--;
    }
    return 0;
}