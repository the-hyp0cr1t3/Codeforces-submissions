/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 12:08:27
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

int simPforPolyphia() {
    int i, n, k;
    cin >> n >> k;
    for(i = 0; i < k; i++)
        cout << string(n/k, char('a'+i));
    cout << string(n%k, 'a') << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) simPforPolyphia();
} // ~W