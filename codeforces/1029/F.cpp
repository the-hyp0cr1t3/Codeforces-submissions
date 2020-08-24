/**
 🍪 the_hyp0cr1t3
 🍪 25.08.2020 01:28:43
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
// #define int long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 1e6;

int32_t main() {
    aylmao
    ll i, a, b, ans = DESPACITO;
    cin >> a >> b;
    if(a < b) swap(a, b);
    vector<pair<ll, ll>> store[2];
    store[0].reserve(N); store[1].reserve(N);
    for(i = 1; i*i <= a; i++)
        if(a%i == 0) store[0].pb(i, a/i);
    for(i = 1; i*i <= b; i++)
        if(b%i == 0) store[1].pb(i, b/i);
    a += b;
    for(i = 1; i*i <= a; i++) {
        if(a%i) continue;
        auto it = upper_bound(all(store[0]), pair<ll, ll>(i, DESPACITO));
        if(it != store[0].begin() and (--it)->second <= a/i) chmin(ans, i + a/i << 1);
        it = upper_bound(all(store[1]), pair<ll, ll>(i, DESPACITO));
        if(it != store[1].begin() and (--it)->second <= a/i) chmin(ans, i + a/i << 1);
    }
    cout << ans;
    return 0;
}