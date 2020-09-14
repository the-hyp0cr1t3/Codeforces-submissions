/**
 🍪 the_hyp0cr1t3
 🍪 14.09.2020 15:54:54
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e5 + 5;

int32_t main() {
    aylmao
    int i, n, m; ll xa, xb;
    cin >> n >> m >> xa >> xb;
    vector<ll> a(n), b(m), l(m);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;
    for(auto& x: l) cin >> x;
    tuple<double, int, int> best = {DESPACITO, -1, -1};

    auto check = [&](int idx_a, int idx_b) {
        double seg = sqrt((xa-xb)*(xa-xb) + (b[idx_b]-a[idx_a])*(b[idx_b]-a[idx_a]));
        seg += sqrt(xa*xa + a[idx_a]*a[idx_a]);
        seg += l[idx_b];
        return make_tuple(seg, idx_a+1, idx_b+1);
    };

    auto TernarySearch = [&](int idx_b) {
        int lo = 0, hi = n-1;
        while(hi - lo > 3) {
            int mid = lo + hi >> 1;
            if(check(mid, idx_b) > check(mid+1, idx_b)) lo = mid;
            else hi = mid+1;
        }
        for(int j = lo; j <= hi; j++)
            chmin(best, check(j, idx_b));
    };

    for(i = 0; i < m; i++) TernarySearch(i);
    cout << get<1>(best) << " " << get<2>(best) << '\n';
}