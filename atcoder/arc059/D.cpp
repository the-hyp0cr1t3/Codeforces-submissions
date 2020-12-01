/**
 🍪 the_hyp0cr1t3
 🍪 01.12.2020 10:48:24
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; string s;
    cin >> s; n = sz(s);
    
    for(char c = 'a'; c <= 'z'; c++) {
        int cur = 0, curlen = 0;
        for(i = 0; i < n; i++) {
            if(s[i] == c) {
                if(++cur and ++curlen > 1)
                    return cout << i-curlen+2 << ' ' << i+1, 0;
            } else {
                if(!cur--) cur = 0, curlen = 0;
                else curlen++;
            }
        }
    }
    cout << -1 << ' ' << -1;
} // ~W 