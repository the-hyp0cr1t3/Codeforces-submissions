/**
 🍪 the_hyp0cr1t3
 🍪 02.11.2020 20:48:24
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 3e5 + 5;
int a[N];

int the_real_main() {
    int i, j, n;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    bool bad = 0;
    int cur = INF, reqd = 0;
    for(i = n-1; ~i; i--) {
        if(a[i] - reqd < 0) bad = 1;
        a[i] -= reqd;
        reqd += max(a[i] - cur, 0);
        chmin(cur, a[i]);
    }
    cout << (bad? "NO" : "YES") << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}