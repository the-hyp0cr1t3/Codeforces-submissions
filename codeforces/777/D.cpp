/**
 🍪 the_hyp0cr1t3
 🍪 14.09.2020 11:28:05
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

const int N = 5e5 + 5;

int32_t main() {
    aylmao
    int i, j, k, n;
    cin >> n;
    vector<string> a(n);
    for(auto& x: a) cin >> x;

    for(i = n-2; ~i; i--) {
        if(a[i] <= a[i+1]) continue;
        for(j = 1; j < min(sz(a[i]), sz(a[i+1])); j++)
            if(a[i][j] != a[i+1][j]) break;
        a[i].erase(j);
    }
 
    for(auto& x: a) cout << x << '\n';
}