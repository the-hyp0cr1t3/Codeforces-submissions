/**
 🍪 the_hyp0cr1t3
 🍪 30.11.2020 20:42:10
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
    int i, n, x, ans = 0;
    cin >> n >> x;
    vector<int> a(n);
    for(auto& x: a)
        cin >> x;

    for(i = 0; i < n; ) {
        if(is_sorted(a.begin()+i, a.end()))
            break;
        while(i < n and a[i] <= x) i++;
        if(i == n) return cout << -1 << '\n', 0;
        swap(a[i], x); ans++;
    }

    cout << (is_sorted(a.begin(), a.end())? ans : -1) << '\n';

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W