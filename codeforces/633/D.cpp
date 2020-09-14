/**
 🍪 the_hyp0cr1t3
 🍪 14.09.2020 17:27:54
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int32_t main() {
    aylmao
    int i, j, n;
    cin >> n;
    vector<int> a(n);
    map<int64_t, int> f; 
    for(auto& x: a) cin >> x, f[x]++;
    int ans = count(all(a), 0);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(!a[i] and !a[j] or i == j) continue;
            int64_t l = a[i], r = a[j];
            f[l]--; f[r]--;
            vector<int64_t> chosen{l, r};
            int res = 2;
            while(f[l+r]) {
                chosen.pb(l+r); res++;
                f[l+r]--; r += l; l = r-l;
            } chmax(ans, res);
            while(sz(chosen)) f[chosen.back()]++, chosen.pop_back();
        }
    } cout << ans << '\n';
}