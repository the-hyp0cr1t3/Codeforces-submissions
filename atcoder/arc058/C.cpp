/**
 🍪 the_hyp0cr1t3
 🍪 07.10.2020 14:36:19
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
    int i, n, k;
    cin >> n >> k;
    vector<int> ok(10, 1);
    for(i = 0; i < k; i++) {
        int d; cin >> d;
        ok[d] = 0;
    }

    auto Try = [&](int x) {
        while(x) {
            if(!ok[x%10]) return false;
            x /= 10;
        } return true;
    };

    while(true) {
        if(Try(n)) return cout << n, 0;
        ++n;
    }
}