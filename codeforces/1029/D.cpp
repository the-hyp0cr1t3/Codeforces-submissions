/**
 🍪 the_hyp0cr1t3
 🍪 24.08.2020 23:58:26
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
#define int long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e5+5;
const int LEN = 10;
int a[N];
unordered_map<int, int> mods[LEN+1];

int32_t main() {
    aylmao
    int i, j, n, k; ll ans = 0;
    cin >> n >> k;
    for(i = 0; i < n; i++) {
        cin >> a[i]; assert(a[i]);
        ll x = a[i] % k;
        for(j = 1; j <= LEN; j++) {
            x *= 10;
            x %= k;
            assert(x >= 0 and x < k);
            mods[j][x]++;
        }
    }

    auto getlen = [](int x) {
        int res = 0; while(x) res++, x /= 10; return res;
    };

    for(i = 0; i < n; i++) {
        int len = getlen(a[i]);
        ll x = k - a[i] % k; x %= k;
        assert(x >= 0 and x < k);
        ans += mods[len][x];
        ll y = a[i] % k;
        for(j = 1; j <= len; j++) 
            y *= 10, y %= k;
        if(x == y) ans--;
    }

    cout << ans; 
    return 0;
}