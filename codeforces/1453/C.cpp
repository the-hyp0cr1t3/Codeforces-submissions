/**
 🍪 the_hyp0cr1t3
 🍪 04.12.2020 19:16:30
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int ocoiek() {
    int i, j, n;
    cin >> n;
    array<int, 10> ans{};

    auto Try = [&](const vector<string>& a) {
        array<int, 10> l, r; int c;
        l.fill(n); r.fill(-1);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                chmin(l[a[i][j]-'0'], j), chmax(r[a[i][j]-'0'], j);
        for(j = 0; j < n; j++)
            for(i = 0; i < n; i++)
                chmax(ans[a[i][j]-'0'], max(i, n-1-i)
                    * max({0, j-l[a[i][j]-'0'], r[a[i][j]-'0']-j}));
    };

    vector<string> a(n);
    for(auto& x: a) cin >> x;
    Try(a);
    for(i = 0; i < n; i++)
        for(j = 0; j < i; j++)
            swap(a[i][j], a[j][i]);
    Try(a);

    for(i = 0; i < 10; i++)
        cout << ans[i] << " \n"[i == 9];
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 