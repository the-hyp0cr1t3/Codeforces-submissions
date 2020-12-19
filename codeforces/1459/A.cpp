/**
 🍪 the_hyp0cr1t3
 🍪 19.12.2020 17:29:30
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

int ocoiek() {
    int i, n, win = 0; string a, b;
    cin >> n >> a >> b;
    for(i = 0; i < n; i++) {
        if(a[i] > b[i]) win++;
        if(a[i] < b[i]) win--;
    }
    cout << (win > 0? "RED" : win < 0? "BLUE" : "EQUAL") << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 