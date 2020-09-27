/**
 🍪 the_hyp0cr1t3
 🍪 27.09.2020 20:40:19
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int the_real_main() {
    int i, n, T;
    cin >> n >> T;
    vector<pair<int, int>> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    } sort(all(a));

    vector<int> ans(n);

    int cntl = 0, cntr = 0;
    for(i = 0; i < n; i++) {
        if(T%2 == 0 and a[i].first == T/2) {
            if(cntl < cntr) ans[a[i].second] = 1, cntl++;
            else cntr++;
        }
        else if(a[i].first <= T/2) ans[a[i].second] = 1;
    }
    for(i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n-1];
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}