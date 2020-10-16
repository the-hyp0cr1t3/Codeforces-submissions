/**
 🍪 the_hyp0cr1t3
 🍪 16.10.2020 17:44:55
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
    int i, n, m; int64_t sum = 0;
    cin >> n >> m;
    vector<int64_t> ans(n+2), pref(n+2);
    vector<int> a(m);
    for(auto& x: a) cin >> x;

    for(i = 1; i < m; i++) {
        if(a[i] == a[i-1]) continue;
        sum += abs(a[i]-a[i-1]);
        if(a[i] > a[i-1]) {
            if(a[i] - a[i-1] > 1) {
                pref[a[i-1]+1]--;
                pref[a[i]]++;                
            }
            ans[a[i]] += max(1, a[i-1]) - abs(a[i]-a[i-1]);
            ans[a[i-1]] += max(1, a[i]-1) - abs(a[i]-a[i-1]);
        } else {
            if(a[i-1] - a[i] > 1) {
                pref[a[i]+1]--;
                pref[a[i-1]]++;
            }
            ans[a[i]] += max(1, a[i-1]-1) - abs(a[i]-a[i-1]);
            ans[a[i-1]] += max(1, a[i]) - abs(a[i]-a[i-1]);            
        }
    }

    for(i = 1; i <= n; i++) {
        pref[i] += pref[i-1];
        cout << sum + pref[i] + ans[i] << " \n"[i == n];
    }
}