/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 12:11:57
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
    int i, n;
    cin >> n; n = 2*n - 2;
    vector<pair<string, int>> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a), [](const auto& A, const auto& B) { return sz(A.first) > sz(B.first); });

    auto Try = [&](int pref) -> string {
        string ans(n, 'S');
        ans[a[pref].second] = 'P';
        for(i = 2; i < n; i += 2) {
            if(a[i].first == a[pref].first.substr(0, sz(a[i].first))
                and a[i+1].first == a[pref^1].first.substr(sz(a[pref^1].first)-sz(a[i+1].first)))
                ans[a[i].second] = 'P';
            else if(a[i+1].first == a[pref].first.substr(0, sz(a[i+1].first))
                and a[i].first == a[pref^1].first.substr(sz(a[pref^1].first)-sz(a[i].first)))
                ans[a[i+1].second] = 'P';
            else return "";
        } return ans;
    };

    cout << max(Try(0), Try(1)) << '\n';
} // ~W