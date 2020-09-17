/**
 🍪 the_hyp0cr1t3
 🍪 17.09.2020 12:43:11
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
    int i, n; string s, t; double ans = 0;
    cin >> n >> s >> t;
    s = '#' + s + '#'; t = '#' + t + '#';

    auto precomp = [&]() {
        vector<vector<int64_t>> a(n+2, vector<int64_t>(26));
        for(i = 1; i <= n; i++) {
            a[i] = a[i-1];
            a[i][t[i]-'A'] += i;
        } return a;
    };

    auto pref = precomp();
    reverse(all(t));
    auto suf = precomp();
    reverse(all(t)); reverse(all(suf));

    double total = 6.0 / (1ll*n*(n+1)*(2*n+1));

    for(i = 1; i <= n; i++) {
        ans += total * pref[i][s[i]-'A'] * (n-i+1);
        ans += total * suf[i+1][s[i]-'A'] * i;
    }

    cout << fixed << setprecision(8) << ans << '\n';
}