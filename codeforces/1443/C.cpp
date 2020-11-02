/**
 🍪 the_hyp0cr1t3
 🍪 02.11.2020 20:31:28
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
const int M = 1e9 + 69;
int a[N], b[N];

int the_real_main() {
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        cin >> b[i];

    auto check = [&](int t) {
        int64_t sum = 0;
        for(i = 0; i < n; i++)
            if(a[i] > t) sum += b[i];
        return sum <= t;
    };

    int lo = 1, hi = M;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(check(mid)) hi = mid - 1;
        else lo = mid + 1;
    } cout << lo << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}