/**
 🍪 the_hyp0cr1t3
 🍪 05.12.2020 17:50:56
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
const string w = "110";
const int64_t T = 1e10;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n; string s; int64_t ans = 0;
    cin >> n >> s;
    for(j = 0; j < 3; j++) {
        bool bad = false;
        for(i = 0; i < n and !bad; i++)
            if(s[i] ^ w[(j+i)%3]) bad = true;
        if(bad) continue;
        int len = (n+j+2)/3;
        ans += T - len + 1;
    } cout << ans;
} // ~W 