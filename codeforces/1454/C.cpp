/**
 🍪 the_hyp0cr1t3
 🍪 24.11.2020 21:35:59
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
#include <ext/pb_ds/assoc_container.hpp>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename K, typename V, typename Hash = custom_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int ocoiek() {
    int i, n;
    cin >> n;
    vector<vector<int>> pos(n+1);
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x].pb(i);
    }

    int ans = INF;
    for(i = 1; i <= n; i++) {
        if(pos[i].empty()) continue;
        int res = !!pos[i][0]; pos[i].pb(n);
        for(int j = 0; j < sz(pos[i])-1; j++) {
            res += !!(pos[i][j+1] - pos[i][j] - 1);
        } ans = min(ans, res);
    } cout << ans << '\n';

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W