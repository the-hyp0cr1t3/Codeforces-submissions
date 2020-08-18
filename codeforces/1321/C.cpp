/**
 🍪 the_hyp0cr1t3
 🍪 18.08.2020 18:47:33
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
// #define int long long
#define endl '\n'
#define pb emplace_back
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5+5;

int32_t main() {
    aylmao
    int n; string S;
    cin >> n >> S;
    auto reduce = [&](string s, char z) {
        string t;
        for(int i = 0; i < sz(s); i++) {
            if(s[i] == z) {
                if(sz(t) and t.back()+1 == z) continue;
                if(i+1 < n and s[i+1]+1 == z) continue;
            }
            t += s[i];
        }
        return t;
    };
    for(char z = 'z'; z > 'a'; z--) {
        S = reduce(S, z);
        reverse(all(S));
        S = reduce(S, z);
    }
    cout << n - sz(S);
    return 0;
}