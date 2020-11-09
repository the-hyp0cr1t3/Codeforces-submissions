/**
 🍪 the_hyp0cr1t3
 🍪 09.11.2020 19:14:16
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb push_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, k;
    cin >> n;
    vector<array<int, 3>> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i][1] >> a[i][0], a[i][2] = i+1;
    sort(all(a), [](const auto& A, const auto& B) { 
        return A[0] == B[0]? A[1] < B[1] : A[0] > B[0]; 
    });
    
    cin >> k;
    multiset<array<int, 2>> r;
    for(i = 0; i < k; i++) {
        int x; cin >> x;
        r.insert({x, i+1});
    }

    int ans = 0;
    vector<pair<int, int>> chosen;
    for(auto& [gain, reqd, id]: a) {
        auto it = r.lower_bound({reqd, -1});
        if(it == r.end()) continue;
        chosen.pb({id, (*it)[1]});
        ans += gain; r.erase(it);
    }

    cout << sz(chosen) << ' ' << ans << '\n';
    for(auto& [x, y]: chosen)
        cout << x << ' ' << y << '\n';
} // ~W