/**
 🍪 the_hyp0cr1t3
 🍪 01.11.2020 01:07:03
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
int f[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, k;
    cin >> n >> k;
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        f[x]++;
    }

    auto check = [&](int x) {
        vector<int> res; res.reserve(k);
        for(i = 1; i < N and sz(res) < k; i++) {
            if(f[i] >= x) {
                int y = 0;
                while(sz(res) < k and y+x <= f[i]) res.pb(i), y += x;
            }
        } return res;
    };

    int lo = 1, hi = n;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(sz(check(mid)) == k) lo = mid + 1;
        else hi = mid - 1;
    }

    for(auto x: check(hi)) cout << x << ' ';
}