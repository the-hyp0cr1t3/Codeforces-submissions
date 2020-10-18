/**
 🍪 the_hyp0cr1t3
 🍪 18.10.2020 14:48:44
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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; string s;
    cin >> s; n = sz(s);
    vector<pair<char, int>> ans;
    while(sz(s) <= 3) {
        ans.pb('L', 2);
        s = s[1] + s;
    }
    ans.pb('L', 2);
    s = s[1] + s;
    ans.pb('R', 2);
    string t = s.substr(1, sz(s)-2);
    reverse(all(t));
    s = s + t;
    ans.pb('R', sz(s)-1);

    cout << sz(ans) << '\n';
    for(auto [u, v]: ans) cout << u << ' ' << v << '\n';
}