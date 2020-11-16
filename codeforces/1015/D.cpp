/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 18:28:20
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
    int64_t i, n, k, S;
    cin >> n >> k >> S;
    
    if(k > S or (n-1) * k < S)
        return cout << "NO" << '\n', 0;

    auto kek = [&](int64_t x, int64_t y) {
        cout << "YES" << '\n';
        int64_t cur = 1;
        for(i = 1; i <= x; i++) {
            cout << (cur = (cur == 1? n : 1ll)) << ' ';
        }
        int o = cur == n;
        for(; i < k; i++, o ^= 1)
            cout << (o? --cur : ++cur) << ' ';
        cout << (cur+y <= n? cur+y : cur-y) << '\n';
        exit(0);
    };

    for(i = 0; i <= k; i++) {
        int64_t res = i * (n-1) + max(0ll, k-i-1);
        if(S - res < n-(k-i-1&1) and S - res > 0) kek(i, S-res);
    }

    cout << "NO" << '\n';
} // ~W