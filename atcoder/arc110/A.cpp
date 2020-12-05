/**
 🍪 the_hyp0cr1t3
 🍪 05.12.2020 17:38:00
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
const array primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    array<int, 10> ans{};
    for(i = 2; i <= n; i++) {
        for(int p = 0; p < 10; p++) {
            int j = i, cnt = 0;
            while(j % primes[p] == 0) cnt++, j /= primes[p];
            ans[p] = max(ans[p], cnt);
        }
    }
    int64_t res = 1;
    for(int p = 0; p < 10; p++)
        while(ans[p]--) res *= primes[p];
    cout << ++res;
} // ~W 