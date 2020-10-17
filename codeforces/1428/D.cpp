/**
 🍪 the_hyp0cr1t3
 🍪 17.10.2020 20:09:40
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
int a[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    array<deque<pair<int, int>>, 4> cols;
    vector<pair<int, int>> ans;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        cols[a[i]].pb(-1, i);
    }

    auto kek = []() {
        cout << -1;
        exit(0);
    };

    if(sz(cols[2]) > sz(cols[1])) kek();

    // place all 1s
    int currow = n+1 - sz(cols[1]);
    for(auto& [r, j]: cols[1]) {
        r = currow;
        ans.pb(currow++, j);
    }

    // place each 2 before a 1
    for(auto [r, j]: cols[2]) {
        while(sz(cols[1])) {
            int k = cols[1].front().second;
            if(k >= j or a[k] == 2) break;
            cols[1].pop_front();
        }
        auto [k, c] = cols[1].front();
        if(cols[1].empty() or a[c] == 2) kek();
        ans.pb(k, j);
        cols[1].pb(k, j);
        cols[1].pop_front();
    }
    
    // finally place all 3s
    currow = 1;
    while(sz(cols[3]) > 1) {
        auto [r, j] = cols[3].front();
        ans.pb(currow, j);
        ans.pb(currow++, cols[3][1].second);
        cols[3].pop_front();
    }

    if(sz(cols[3])) {
        if(cols[1].empty()) kek();
        auto [lst, mxcol] = *max_element(all(cols[1]));
        auto [r, j] = cols[3].front();
        if(mxcol < j) kek();
        ans.pb(currow, j);
        ans.pb(currow, mxcol);
    }

    cout << sz(ans) << '\n';
    for(auto [u, v]: ans) cout << u << ' ' << v << '\n';
}