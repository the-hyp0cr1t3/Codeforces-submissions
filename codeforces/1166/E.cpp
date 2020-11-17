/**
 🍪 the_hyp0cr1t3
 🍪 17.11.2020 14:45:51
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
const int N = 1e4 + 5;
bitset<N> masks[55];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, m, n;
    cin >> m >> n;

    for(i = 0; i < m; i++) {
        int q; cin >> q;
        while(q--) {
            int x; cin >> x;
            masks[i][x] = 1;
        }
    }

    for(i = 0; i < m; i++)
        for(j = 0; j < i; j++)
            if(!(masks[i] & masks[j]).count())
                return cout << "impossible", 0;
    
    cout << "possible";
} // ~W