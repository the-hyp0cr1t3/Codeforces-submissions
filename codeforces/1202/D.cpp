#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define pb push_back
#define sz(x) (int)(x).size()
const int N = 1e5 + 5;
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        string s = "133";
        int sev, three = 2, i, n;
        cin >> n;
        while (three*(three-1)/2 <= n) three++;
        three--;
        sev = n - (three*(three-1)/2);
        for(i = 0; i < sev; i++) 
            s += '7';
        for(i = 0; i < three-2; i++) 
            s += '3';
        s += '7';
        cout << s << endl;
    }
    return 0;
}