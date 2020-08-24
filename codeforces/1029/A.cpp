/**
 🍪 the_hyp0cr1t3
 🍪 24.08.2020 23:24:26
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

const int N = 2e5+5;

int32_t main() {
    aylmao
    int i, j, n, k, z; string s, ans;
    cin >> n >> k >> s;
    auto check = [&](int x) {
        for(i = x-1, j = n-1; ~i; i--, j--) 
            if(s[j]^s[i]) return false;
        return true;
    };
    int mx = 0;
    for(z = 1; z < n; z++) 
        if(check(z)) chmax(mx, z);
    for(i = 0; i < k-1; i++) 
        ans += s.substr(0, n-mx);
    ans += s;
    cout << ans;
    return 0;
}