/**
 🍪 the_hyp0cr1t3
 🍪 15.11.2020 20:06:12
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

void kek(const vector<pair<int, int>>& a) {
    cout << sz(a) << '\n';
    for(auto [x, y]: a)
        cout << y << ' ';
    cout << '\n';
}

int simPforPolyphia() {
    int i, n; int64_t S, sum = 0;
    cin >> n >> S;
    vector<pair<int, int>> a(n), b;
    b.reserve(n);
    for(i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(all(a));
    for(i = 0; i < n and sum < (S+1)/2; i++) {
        if(a[i].first >= (S+1)/2 and a[i].first <= S) {
            b.clear(); b.pb(a[i]);
            return kek(b), 0;
        }
        sum += a[i].first;
        b.pb(a[i]);
    }
    if(sum >= (S+1)/2 and sum <= S)
        return kek(b), 0;
    return cout << -1 << '\n', 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) simPforPolyphia();
} // ~W