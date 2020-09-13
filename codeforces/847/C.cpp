/**
 🍪 the_hyp0cr1t3
 🍪 13.09.2020 21:02:59
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
    int i; ll n, k;
    cin >> n >> k;
    if(n*(n-1)/2 < k) return cout << "Impossible" , 0;

    int lo = 1, hi = n;
    while(lo <= hi) {
        ll mid = lo + hi >> 1;
        if(mid*(mid-1)/2 <= k) lo = mid + 1;
        else hi = mid - 1;
    }

    string ans = string(hi, '(') + string(hi, ')');
    k -= 1ll*hi*(hi-1)/2; n -= hi;
    assert(k < hi);
    if(n) ans.insert(k, "()"), n--;
    for(i = 0; i < n; i++) ans += "()";
    
    cout << ans << '\n';
}