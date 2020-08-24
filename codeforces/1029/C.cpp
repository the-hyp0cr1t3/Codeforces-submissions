/**
 🍪 the_hyp0cr1t3
 🍪 24.08.2020 23:49:55
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
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

const int N = 3e5+5;
int pref[N][2], suf[N][2];

int32_t main() {
    aylmao
    int i, n, ans = 0;
    cin >> n;
    pref[0][1] = suf[n+1][1] = INF;
    for(i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        suf[i][0] = l;
        suf[i][1] = r;
        pref[i][0] = max(l, pref[i-1][0]);
        pref[i][1] = min(r, pref[i-1][1]);
    }
    for(i = n; i; i--) {
        chmax(suf[i][0], suf[i+1][0]);
        chmin(suf[i][1], suf[i+1][1]);        
    }
    for(i = 1; i <= n; i++) 
        chmax(ans, min(pref[i-1][1], suf[i+1][1])-max(pref[i-1][0], suf[i+1][0]));
    cout << ans;
    return 0;
}