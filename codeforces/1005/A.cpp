/**
 🍪 the_hyp0cr1t3
 🍪 16.09.2020 22:55:42
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
int a[N];

int32_t main() {
    aylmao
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    vector<int> ans;
    for(i = 1; i < n; i++)
        if(a[i] != a[i-1] + 1) ans.pb(a[i-1]);
    ans.pb(a[n-1]);
    cout << sz(ans) << '\n';
    for(auto x: ans) cout << x << ' ';
}