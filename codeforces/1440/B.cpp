/**
 🍪 the_hyp0cr1t3
 🍪 18.11.2020 14:00:35
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
const int N = 1e6 + 5;
int64_t a[N];

int simPforPolyphia() {
    int i, n, k; int64_t ans = 0;
    cin >> n >> k;
    for(i = 0; i < n*k; i++)
        cin >> a[i];
    for(i = k*((n-1)/2); i < n*k; i += n-(n-1)/2)
        ans += a[i];
    cout << ans << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) simPforPolyphia();
} // ~W