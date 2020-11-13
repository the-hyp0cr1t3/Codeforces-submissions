/**
 🍪 the_hyp0cr1t3
 🍪 13.11.2020 22:22:42
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
    int i, n, X = 0;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i].first; a[i].second = i+1;
    } sort(all(a));

    vector<tuple<int, int, int>> ans, pairs;
    ans.reserve(n); pairs.reserve(n/2);
    queue<pair<int, int>> q;

    for(i = 0; i < n; i++) {
        if(i+1 < n and a[i].first == a[i+1].first)
            pairs.pb(a[i].first, a[i].second, a[i+1].second), i++;
        else q.push(a[i]);
    }

    while(sz(q) >= 3) {
        auto [a, x] = q.front(); q.pop();
        auto [b, y] = q.front(); q.pop();
        auto [c, z] = q.front(); q.pop();
        ans.pb(x, y, z);
        pairs.pb(a^b^c, x, y);
        q.emplace(a^b^c, z);
    }

    if(sz(q) == 2) {
        auto [a, x] = q.front(); q.pop();
        auto [b, y] = q.front(); q.pop();
        if(a^b) return cout << "NO" << '\n', 0;
        pairs.pb(a, x, y);
    }
    
    int val, idx;
    if(q.empty()) {
        tie(val, idx, idx) = pairs.back();
        pairs.pop_back();
    } else {
        tie(val, idx) = q.front();
    }

    while(!pairs.empty()) {
        auto [v, i, j] = pairs.back();
        if(v^val) ans.pb(idx, i, j);
        pairs.pop_back();
    }

    cout << "YES" << '\n' << sz(ans) << '\n';
    for(auto [x, y, z]: ans)
        cout << x << ' ' << y << ' ' << z << '\n';
} // ~W