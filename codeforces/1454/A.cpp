/**
 🍪 the_hyp0cr1t3
 🍪 24.11.2020 21:51:10
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

int ocoiek() {
    int i, n;
    cin >> n;
    vector<int> ans(n);
    iota(all(ans), 1);
    rotate(ans.begin(), ans.begin()+1, ans.end());
    for(auto a: ans) cout << a << ' ';
    cout << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W