/**
 🍪 the_hyp0cr1t3
 🍪 21.08.2020 10:40:53
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
int a[N], lst[N], dp[N];

int32_t main() {
    aylmao
    int i, j, n, S, l;
    cin >> n >> S >> l;
    for(i = 1; i <= n; i++) 
        cin >> a[i];

    auto push = [&](auto& q, auto&& f, pii x) {
        while(!q.empty() and f(x.first, q.back().first)) q.pop_back();
        q.pb(x);
    };
    auto pop = [&](auto& q) {
        while(!q.empty() and q.front().second < j) q.pop_front();
    };

    deque<pii> mxq, mnq, q;
    for(i=j=1; i <= n; i++) {
        push(mxq, greater_equal<int>{}, {a[i], i});
        push(mnq, less_equal<int>{}, {a[i], i});
        pop(mxq); pop(mnq);
        while(mxq.front().first - mnq.front().first > S)
            j++, pop(mxq), pop(mnq);
        lst[i] = j;
    }

    dp[0] = 1;
    for(i = l; i <= n; i++) {
        if(dp[i-l]) push(q, less_equal<int>{}, {dp[i-l], i-l});
        j = lst[i]-1; pop(q);
        if(!q.empty()) dp[i] = q.front().first + 1;
    }

    cout << dp[n]-1;
    return 0;
}