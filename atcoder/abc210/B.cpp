/**
 🍪 the_hyp0cr1t3
 🍪 17.07.2021 17:32:18
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n; string s;
    cin >> n >> s;
    for(i = 0; i < n; i++)
        if(s[i] == '1') break;
    cout << (i & 1? "Aoki" : "Takahashi");
} // ~W