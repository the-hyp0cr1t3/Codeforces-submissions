/**
 🍪 the_hyp0cr1t3
 🍪 16.09.2020 23:01:51
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
int a[N];

int32_t main() {
    aylmao
    int i, j, n, ans = 0;
    cin >> n;
    multiset<int> active;
    for(i = 0; i < n; i++)
        cin >> a[i], active.insert(a[i]);

    for(i = 0; i < n; i++) {
        active.erase(active.find(a[i]));
        for(j = 0; j < 31; j++)
            if(active.find((1<<j) - a[i]) != active.end()) break;
        if(j == 31) ans++;
        active.insert(a[i]);
    }

    cout << ans;
}