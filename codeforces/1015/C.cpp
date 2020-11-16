/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 18:21:45
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
int a[N], b[N], c[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; int64_t m, sum = 0;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    iota(c, c+n, 0);
    sort(c, c+n, [&](int A, int B) { return a[A]-b[A] > a[B]-b[B]; });

    sum = accumulate(a, a+n, 0ll);
    for(i = 0; i < n; i++) {
        if(sum <= m) return cout << i << '\n', 0;
        sum -= a[c[i]] - b[c[i]];
    }

    cout << (sum <= m? n : -1) << '\n';
} // ~W