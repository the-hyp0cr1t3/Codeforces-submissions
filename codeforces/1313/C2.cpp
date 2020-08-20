/**
 🍪 the_hyp0cr1t3
 🍪 20.08.2020 22:39:50
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

const int N = 5e5+5;
int a[N];

int32_t main() {
    aylmao
    int i, n;
    cin >> n;
    for(i = 1; i <= n; i++) 
        cin >> a[i];

    auto work = [&]() {
        vector<ll> v(n+2);
        stack<pii> st; st.push({-1, 0});
        ll sum = 0;
        for(i = 1; i <= n; i++) {
            while(a[i] <= st.top().first) {
                auto [val, j] = st.top();
                st.pop();
                sum -= 1ll*val*(j-st.top().second);
            }
            auto [val, j] = st.top();
            sum += 1ll*a[i]*(i-j);
            st.push({a[i], i});
            v[i] = sum;
        }
        return v;
    };

    auto pref = work();
    reverse(a+1, a+1+n);
    auto suf = work();
    reverse(all(suf));
    reverse(a+1, a+1+n);
    
    ll ans = 0; int best, cur = INF;
    for(i = 1; i <= n; i++) 
        if(chmax(ans, pref[i]+suf[i]-a[i])) best = i;

    for(cur = a[best], i = best-1; i; cur = a[i--]) chmin(a[i], cur);
    for(cur = a[best], i = best+1; i <= n; cur = a[i++]) chmin(a[i], cur);

    for(i = 1; i <= n; i++) 
        cout << a[i] << " \n"[i == n];        
    return 0;
}