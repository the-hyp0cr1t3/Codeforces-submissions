/**
 🍪 the_hyp0cr1t3
 🍪 01.11.2020 02:55:58
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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, k, x;
    cin >> n >> k >> x;
    vector<deque<array<int64_t, 2>>> q(x+1);
    q[0].pb(); q[0][0][1] = -1;
    for(i = 0; i < n; i++) {
        int64_t a; cin >> a;
        for(j = x-1; ~j; j--) {
            while(!q[j].empty() and q[j].front()[1] < i-k) q[j].pop_front();
            if(q[j].empty()) continue;
            int64_t z = a + q[j].front()[0];
            while(!q[j+1].empty() and q[j+1].back()[0] <= z) q[j+1].pop_back();
            q[j+1].push_back({z, i});            
        }
    } while(!q[x].empty() and q[x].front()[1] < n-k) q[x].pop_front();
    cout << (q[x].empty()? -1 : q[x].front()[0]) << '\n';
}