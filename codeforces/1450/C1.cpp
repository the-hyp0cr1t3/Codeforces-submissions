/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 20:34:51
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int ocoiek() {
    int i, j, n;
    cin >> n;
    vector<string> a(n);
    for(auto& x: a) cin >> x;

    auto Try = [&](auto& b, int s) {
        int cnt = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(b[i][j] != 'X') continue;
                if((i+j)%3 == s) b[i][j] = 'O', cnt++;
            }
        } return cnt;
    };

    int best = INF, y;
    for(int z = 0; z < 3; z++) {
        auto b = a;
        if(chmin(best, Try(b, z))) y = z;
    }

    Try(a, y);
    for(auto& x: a) cout << x << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 