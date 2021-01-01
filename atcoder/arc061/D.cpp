/**
 🍪 the_hyp0cr1t3
 🍪 01.01.2021 14:10:47
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
namespace Hashing {    
    using hash_t = pair<int, int>;
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const { return splitmix64(x + FIXED_RANDOM); }
        size_t operator()(const hash_t& x) const { return splitmix64(FIXED_RANDOM + x.second) ^ (splitmix64(FIXED_RANDOM + x.first) << 1); }
    };
    
    template<typename K, typename V, typename Hash = custom_hash>
    using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
    
    template<typename K, typename Hash = custom_hash>
    using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

} using namespace Hashing;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m, q;
    cin >> n >> m >> q;
    array<int64_t, 10> ans{};
    ans[0] = 1ll * (n-2) * (m-2);

    set<pair<int, int>> black, used;
    for(i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        black.insert({x, y});
    }

    auto valid = [&](int x, int y) {
        return x > 1 and x < n and y > 1 and y < m;
    };

    for(auto [x, y]: black) {
        for(int dx: {-1, 0, 1}) {
            for(int dy: {-1, 0, 1}) {
                int nx = x + dx;
                int ny = y + dy;
                if(!valid(nx, ny) or used.find({nx, ny}) != used.end())
                    continue;
                int cnt = 0;
                for(int rx: {-1, 0, 1}) {
                    for(int ry: {-1, 0, 1}) {
                        int mx = nx + rx;
                        int my = ny + ry;
                        if(black.find({mx, my}) != black.end()) cnt++;
                    }
                } ans[cnt]++; used.insert({nx, ny});
            }
        }
    }

    ans[0] -= sz(used);
    for(auto x: ans) cout << x << '\n';
} // ~W 