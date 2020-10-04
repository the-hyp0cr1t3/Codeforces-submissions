/**
 🍪 the_hyp0cr1t3
 🍪 04.10.2020 21:39:06
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
const int N = 100 + 5;
int a[N][N];

int the_real_main() {
    int i, j, n, m; int64_t ans = 0;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> a[i][j];

    auto check = [&](int x, vector<int>& v) {
        int64_t res = 0;
        for(int k = 0; k < sz(v); k++)
            res += abs(x-v[k]);
        return res;
    };
    
    auto tern = [&](vector<int>& v) {
        int lo = 0, hi = 1e9+50;
        int64_t res = DESPACITO;
        while(hi - lo > 4) {
            int mid = lo + hi >> 1;
            if(check(mid, v) >= check(mid+1, v)) lo = mid;
            else hi = mid+1;
        }
        for(int z = lo; z <= hi; z++)
            chmin(res, check(z, v));
        return res;
    };

    for(i = 0; i < (n+1)/2; i++) {
        for(j = 0; j < (m+1)/2; j++) {
            vector<int> v{a[i][j]};
            set<pair<int, int>> used;
            used.insert({i, j});
            if(!used.count({n-1-i, j}))
                v.pb(a[n-1-i][j]), used.insert({n-1-i, j});
            if(!used.count({n-1-i, m-1-j}))
                v.pb(a[n-1-i][m-1-j]), used.insert({n-1-i, m-1-j});
            if(!used.count({i, m-1-j}))
                v.pb(a[i][m-1-j]);
            ans += tern(v);
        }
    } cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}