/**
 🍪 thew6rst
 🍪 13.09.2020 12:56:25
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
int a[N];
ll diffs[N];

int32_t main() {
    aylmao
    int i, n, Q; ll ans = 0, base = 0;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        if(i > 1) diffs[i] = a[i]-a[i-1], ans += max(0, a[i]-a[i-1]);
        else base = a[i];
    }
    diffs[1] = diffs[n+1] = -DESPACITO;

    auto get = [&](ll k) {
        k += base;
        if(k & 1 and k > 0) k++;
        return k/2;
    };

    cout << get(ans) << '\n';
    cin >> Q;
    while(Q--) {
        int l, r, x; cin >> l >> r >> x;
        if(l == 1) base += x;

        ans -= max(0ll, diffs[l]);
        diffs[l] += x;
        ans += max(0ll, diffs[l]);

        ans -= max(0ll, diffs[r+1]);
        diffs[r+1] += -x;
        ans += max(0ll, diffs[r+1]);
        
        cout << get(ans) << '\n';
    }
}