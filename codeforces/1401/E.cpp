/**
 🍪 the_hyp0cr1t3
 🍪 21.08.2020 21:53:42
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key
#define fbo find_by_order
#define ff first
#define ss second
#define endl '\n'
#define pb emplace_back
// #define int long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 1'000'000;

int32_t main() {
    aylmao
    int i, n, p, q, j = 0, k = 0; ll ans = 1;
    cin >> n >> p;
    vector<tuple<int, int, int>> hors;
    hors.reserve(n);
    for(i = 0; i < n; i++) {
        int y, lx, rx; cin >> y >> lx >> rx;
        if(!lx) hors.pb(y, rx, 1);
        else hors.pb(y, lx, 0);
        ans += !lx and rx == N;
    }
    sort(all(hors));

    vector<pii> ups, downs;
    ups.reserve(p); downs.reserve(p);
    ordered_set<int> active;
    for(i = 0; i < p; i++) {
        int x, ly, ry; cin >> x >> ly >> ry;
        if(!ly) downs.pb(ry, x), active.insert(x);
        else ups.pb(ly, x);
        ans += !ly and ry == N;
    }
    sort(all(ups)); sort(all(downs));
    p = sz(ups); q = sz(downs);

    for(auto [cur, pos, b]: hors) {
        while(k < q) {
            auto [y, x] = downs[k];
            if(y >= cur) break;
            active.erase(x); k++;
        }
        while(j < p) {
            auto [y, x] = ups[j];
            if(y > cur) break;
            active.insert(x); j++;
        }
        auto cnt = active.ook(pos+b);
        if(!b) cnt = sz(active) - cnt;
        ans += cnt;
    }

    cout << ans;
    return 0;
}
