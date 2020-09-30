/**
 🍪 the_hyp0cr1t3
 🍪 01.10.2020 00:59:51
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
const int M = 100;
int a[N];

int the_real_main() {
    int i, n, l;
    cin >> n >> l;
    for(i = 0; i < n; i++)
        cin >> a[i];

    auto check = [&](double t) {
        int j = 0, prv = 0, v = 1; double x1 = 0, x2 = 0, t1 = t, t2 = t;
        while(t1 > 0 and j < n) {
            double take = min(1.0*(a[j]-prv), t1 * v);
            x1 += take;
            t1 -= take / v;
            v++; prv = a[j++];
        } x1 += min(1.0*(l-prv), t1 * v);
        j = n-1, prv = l, v = 1;
        while(t2 > 0 and ~j) {
            double take = min(1.0*(prv-a[j]), t2 * v);
            x2 += take;
            t2 -= take / v;
            v++; prv = a[j--];
        } x2 += min(1.0*(prv), t2 * v);
        return x1 + x2 > 1.0*l;
    };

    double lo = 0, hi = l;
    for(i = 0; i < M; i++) {
        double mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid;
    } cout << fixed << setprecision(8) << lo << '\n';

    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}