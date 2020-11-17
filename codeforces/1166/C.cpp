/**
 🍪 the_hyp0cr1t3
 🍪 17.11.2020 14:12:21
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
int a[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i], a[i] = abs(a[i]);
    sort(a, a+n);

    int64_t ans = 0;
    for(i = j = 0; i < n; i++) {
        while(j < n and a[j] <= 2*a[i]) j++;
        ans += j-i-1;
    } cout << ans << '\n';
} // ~W