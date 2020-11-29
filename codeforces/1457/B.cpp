/**
 🍪 the_hyp0cr1t3
 🍪 29.11.2020 20:22:09
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
const int M = 101;
int a[N];

int ocoiek() {
    int i, j, n, k, ans = INF;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(int z = 1; z < M; z++) {
        int l = 1, res = 0;
        while(l <= n) {
            if(a[l] == z) {
                l++;
            } else {
                res++; l += k; 
            }
        } ans = min(ans, res);
    } cout << ans << '\n';

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W