/**
 🍪 the_hyp0cr1t3
 🍪 22.12.2020 00:05:41
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
int a[N], fst[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    memset(fst, -1, sizeof(fst));
    for(i = 0; i < n; i++) {
        cin >> a[i];
        if(fst[a[i]] == -1) fst[a[i]] = i;
    }

    map<int, int> f;
    for(i = n-1; i; i--)
        f[a[i]]++;

    int64_t ans = 0;
    for(i = 0; i < n-1; i++) {
        if(fst[a[i]] == i)
            ans += sz(f);
        if(!--f[a[i+1]]) f.erase(a[i+1]);
    }

    cout << ans << '\n';
} // ~W 