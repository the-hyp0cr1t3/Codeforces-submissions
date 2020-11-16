/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 18:17:37
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, k, n; string s, t;
    cin >> n >> s >> t;

    vector<int> ans;
    for(i = 0; i < n; i++) {
        if(s[i] == t[i]) continue;
        j = i+1;
        while(j < n and s[j] != t[i]) j++;
        if(j == n) return cout << -1 << '\n', 0;
        while(j-- > i) ans.pb(j+1), swap(s[j], s[j+1]);
    }

    cout << sz(ans) << '\n';
    for(auto& x: ans) cout << x << ' ';
} // ~W