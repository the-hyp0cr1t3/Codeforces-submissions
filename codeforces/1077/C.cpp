/**
 🍪 the_hyp0cr1t3
 🍪 01.11.2020 00:59:39
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
    int i, n; int64_t sum = 0;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i].first;
        sum += a[i].first;
        a[i].second = i+1;
    }
    sort(all(a));

    vector<int> ans; ans.reserve(n);
    for(i = 0; i < n-1; i++)
        if(sum - a[n-1].first - a[i].first == a[n-1].first) ans.pb(a[i].second);
    if(sum - a[n-1].first - a[n-2].first == a[n-2].first) ans.pb(a[n-1].second);

    cout << sz(ans) << '\n';
    for(auto& x: ans) cout << x << ' ';
}