/**
 🍪 the_hyp0cr1t3
 🍪 30.09.2020 20:05:53
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

int the_real_main() {
    int i, n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        cin >> b[i];
    for(i = 0; i < n; i++)
        cin >> c[i];

    auto Try = [&](vector<int>& ans) {
        for(i = 1; i < n-1; i++) {
            if(a[i] != ans[i-1])
                ans[i] = a[i];
            else if(b[i] != ans[i-1])
                ans[i] = b[i];
            else if(c[i] != ans[i-1])
                ans[i] = c[i];
            else
                return false;
        }
        if(a[i] != ans[i-1] and a[i] != ans[0])
            ans[i] = a[i];
        else if(b[i] != ans[i-1] and b[i] != ans[0])
            ans[i] = b[i];
        else if(c[i] != ans[i-1] and b[i] != ans[0])
            ans[i] = c[i];
        else
            return false;
        return true;
    };
    
    auto print = [&](vector<int>& ans) {
        for(i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n-1];
    };

    vector<int> ans(n);
    ans[0] = a[0];
    if(Try(ans)) return print(ans), 0;
    ans[0] = b[0];
    if(Try(ans)) return print(ans), 0;
    ans[0] = c[0];
    if(Try(ans)) return print(ans), 0;
    assert(false);
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}