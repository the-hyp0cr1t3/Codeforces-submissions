/**
 🍪 the_hyp0cr1t3
 🍪 12.10.2020 19:41:49
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
    int i, j, m, k, free = 0;
    cin >> m >> k; --m;
    string ans(k, 'N');
    vector<int> a(k+1), lst(k+1, -1);
    for(i = 1; i <= k; i++)
        cin >> a[i];
    vector<array<int, 2>> orders(m);
    for(i = 0; i < m; i++) {
        cin >> orders[i][0] >> orders[i][1];
        if(orders[i][0] > 0)
            lst[orders[i][0]] = i;
    }

    bool once = true;
    for(i = 0; i < m; i++) {
        auto [t, r] = orders[i];
        if(r == 1 and once) {
            int mn = INF;
            for(j = 1; j <= k; j++)
                if(lst[j] < i and a[j] <= free)
                    ans[j-1] = 'Y', mn = min(mn, a[j]);
            free -= mn;
            once = false;
        }
        if(t) a[t]--;
        else free++;
    }

    for(i = 1; i <= k; i++) if(a[i] <= free) ans[i-1] = 'Y';
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}