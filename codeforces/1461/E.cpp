/**
 🍪 the_hyp0cr1t3
 🍪 11.12.2020 23:48:00
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
bitset<N> seen;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int64_t k, l, r, t, x, y, b, times;
    cin >> k >> l >> r >> t >> x >> y;
    b = max(l-1, r - y);

    auto kek = [](int64_t o) {
        cout << (o < 0? "Yes" : "No"); exit(0);
    };

    if(x == y) {
        kek(k + y <= r or k-x >= l? -1 : t);
    } else if(x > y) {
        t--;
        k -= (k + y <= r)? x - y : x;
        if(k < l) kek(t);
        kek(t -= (k-l+1+x-y-1)/(x-y));
    } else {
        while(true) {
            if(k + y <= r) {
                times = (b-k+1+y-x-1)/(y-x);
                k += times * (y-x);
                t -= times;
                if(seen[k%x]) kek(-1);
                seen[k%x] = 1;
            } else {
                times = (k-b+x-1)/x;
                t -= times;
                if((k -= times * x) < l) kek(t);
            }
        }
    }
    
} // ~W 