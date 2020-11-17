/**
 🍪 the_hyp0cr1t3
 🍪 17.11.2020 13:48:09
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
int cnt[30];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    while(n--) {
        string s; cin >> s;
        cnt[s[0]-'a']++;
    }

    int ans = 0;
    for(i = 0; i < 26; i++)
        ans += cnt[i]/2 *(cnt[i]/2-1)/2 + (cnt[i]+1)/2 *((cnt[i]+1)/2-1)/2;
    cout << ans << '\n';
} // ~W