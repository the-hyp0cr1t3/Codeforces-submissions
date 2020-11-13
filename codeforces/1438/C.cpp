/**
 🍪 the_hyp0cr1t3
 🍪 13.11.2020 21:12:42
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
const array dx{1, 0, -1, 0};
const array dy{0, 1, 0, -1};
const int N = 1000 + 5;
int a[N][N];

int simPforPolyphia() {
    int i, j, k, n, m;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            cin >> a[i][j];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            a[i][j] += i+j - a[i][j] & 1;

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            cout << a[i][j] << " \n"[j == m];
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) simPforPolyphia();
} // ~W