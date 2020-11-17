/**
 🍪 the_hyp0cr1t3
 🍪 17.11.2020 13:52:50
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
const string w = "aeiou";

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n;
    cin >> n;
    for(j = 5; j*j <= n; j++)
        if(n%j == 0) break;

    if(j*j > n)
        return cout << -1, 0;

    for(int z = 0; z < j; z++)
        for(i = 0; z+i*j < n; i++)
            cout << w[(z+i)%5];
} // ~W