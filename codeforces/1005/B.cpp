/**
 🍪 the_hyp0cr1t3
 🍪 16.09.2020 22:58:52
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
    int i; string s, t;
    cin >> s >> t;
    reverse(all(s));
    reverse(all(t));
    for(i = 0; i < min(sz(s), sz(t)); i++)
        if(s[i]^t[i]) break;
    cout << sz(s) + sz(t) - 2*i;
}