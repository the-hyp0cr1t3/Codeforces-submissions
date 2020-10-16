/**
 🍪 the_hyp0cr1t3
 🍪 16.10.2020 17:18:53
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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, k;
    cin >> n >> k;
    deque<int> q;
    map<int, int> active;
    while(n--) {
        int j; cin >> j; --j;
        if(active[j]) continue;
        active[j] = 1;
        q.pb(j);
        if(sz(q) > k) {
            active.erase(q.front());
            q.pop_front();
        }
    }

    cout << sz(q) << '\n';
    reverse(all(q));
    for(auto x: q) cout << x+1 << ' ';
}