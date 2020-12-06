/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 21:10:24
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
    int i, n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) cin >> x;

    auto go = [&]() {
        stack<int> stk;
        vector<int> lens(n);
        for(i = 0; i < n; i++) {
            while(!empty(stk) and a[stk.top()] >= a[i]) stk.pop();
            lens[i] = i - (empty(stk)? -1 : stk.top());
            stk.push(i);
        } return lens;
    };

    auto len = go();
    reverse(all(a));
    auto len2 = go();
    reverse(all(len2));
    reverse(all(a));
    for(i = 0; i < n; i++)
        len[i] += len2[i] - 1;

    vector<int> have(n+1);
    for(i = 0; i < n; i++)
        chmax(have[a[i]], len[i]);

    have[0] = INF;
    for(i = 1; i <= n; i++)
        chmin(have[i], have[i-1]);

    for(i = n; i; --i)
        cout << (have[i] >= n-i+1);
    cout << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W             