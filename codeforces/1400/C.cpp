/**
 🍪 the_hyp0cr1t3
 🍪 25.08.2020 20:13:56
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

int the_real_main() {
    int i, n, x; string s, ans;
    cin >> s >> x; n = sz(s);
    ans = string(n, 'z');
    for(i = 0; i < x; i++) {
        if(i+x < n) {
            if(s[i] == '1') ans[i+x] = '1';
            else ans[i+x] = '0';
        }
        else {
            if(s[i] == '1') return cout << -1 << endl, 0;
        }
    }
    for(i = 0; i < x; i++) { 
        if(n-1-i-x >= 0) {
            if(s[n-1-i] == '1') {
                if(ans[n-1-i-x] == '0') return cout << -1 << endl, 0;
                else ans[n-1-i-x] = '1';
            }
            else {
                if(ans[n-1-i-x] == '1') return cout << -1 << endl, 0;
                ans[n-1-i-x] = '0';
            }
        }
        else {
            if(s[n-1-i] == '1') return cout << -1 << endl, 0;
        }
    }

    for(i = x; i < n-x; i++) {
        if(s[i] == '0') {
            if(ans[i-x] == '1' or ans[i+x] == '1')
                return cout << -1 << endl, 0;
            ans[i-x] = '0'; ans[i+x] = '0';
        }
    }

    for(i = 0; i < n; i++) 
        if(ans[i] == 'z') ans[i] = '1';

    for(i = x; i < n-x; i++) {
        if(s[i] == '1') {
            if(ans[i-x] == '0' and ans[i+x] == '0')
                return cout << -1 << endl, 0;
        }
    }
    
    cout << ans << endl;
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}