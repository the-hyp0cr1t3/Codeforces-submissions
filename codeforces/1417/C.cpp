/**
 🍪 the_hyp0cr1t3
 🍪 27.09.2020 21:00:22
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
const int N = 2e5 + 5;

int the_real_main() {
    int i, n;
    cin >> n;
    vector<int> mxdiff(n+3, -1), lst(n+1, -1), pref(n+3, INF);
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        chmax(mxdiff[x], i - lst[x]);
        lst[x] = i;
    }

    for(i = 1; i <= n; i++)
        chmax(mxdiff[i], n - lst[i]);
    
    for(i = 1; i <= n; i++)
        if(~mxdiff[i]) chmin(pref[mxdiff[i]], i);

    for(i = 1; i <= n; i++)
        chmin(pref[i], pref[i-1]);

    for(i = 1; i <= n; i++)
        cout << (pref[i] == INF? -1 : pref[i]) << " \n"[i == n];
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}