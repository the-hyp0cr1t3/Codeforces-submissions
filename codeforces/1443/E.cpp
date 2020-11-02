/**
 🍪 the_hyp0cr1t3
 🍪 02.11.2020 23:23:27
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
const int L = 16;
int64_t fact[L+1];

constexpr void precomp() {
    fact[0] = 1;
    for(int i = 1; i <= L; i++)
        fact[i] = fact[i-1] * i;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, Q; int64_t cur = 0;
    cin >> n >> Q;
    int p = max(0, n-L);
    precomp();

    auto sum = [](int64_t x) { return x * (x+1) / 2; };

    auto f = [&](int l, int r, int64_t cur) {
        int64_t ans = l <= p? sum(min(p, r)) - sum(l-1) : 0ll;
        vector<int> have(n-p), now(n-p); iota(all(have), p+1);
        for(int j = p+1, i = n-j; j <= n; j++) {
            int64_t pos = cur / fact[i];
            assert(pos < sz(have));
            cur %= fact[i--];
            if(l <= j and j <= r) ans += have[pos]; have.erase(have.begin()+pos);            
        } return ans;
    };

    while(Q--) {
        int o; cin >> o;
        if(o == 1) {
            int l, r; cin >> l >> r;
            cout << f(l, r, cur) << '\n';
        } else {
            int x; cin >> x;
            cur += x;
        }
    }
}