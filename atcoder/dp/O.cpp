/**
 🍪 the_hyp0cr1t3
 🍪 31.08.2020 18:14:01
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define endl '\n'
#define pb emplace_back
// #define int int64_t
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e5 + 5;

int32_t main() {
    aylmao
    int i, j, n;
    cin >> n;
    vector<int> masks(n), dp(1<<n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            int x; cin >> x;
            masks[i] += x << j;
        }
    }
    auto get = [](string t) {
        int msk = 0;
        for(int z = 0; z < sz(t); z++) 
            msk += (t[z] == '1') << z;
        return msk;
    };
    string s(n, '0');
    dp[0] = 1;
    for(i = 0; i < n; i++) {
        do {
            int msk = get(s);
            for(j = 0; j < n; j++) {
                if(!(masks[i]>>j&1 and !(msk>>j&1))) continue;
                dp[msk|1<<j] += dp[msk];
                if(dp[msk|1<<j] >= MOD) dp[msk|1<<j] -= MOD;
            }
        } while(next_permutation(all(s)));
        s[n-1-i] = '1';
    }
    cout << dp[(1<<n)-1];
    return 0;
}