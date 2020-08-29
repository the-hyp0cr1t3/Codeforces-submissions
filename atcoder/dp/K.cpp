/**
 🍪 the_hyp0cr1t3
 🍪 29.08.2020 12:45:27
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

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int N = 2e5+5;
int a[N], cache[N][2];

int32_t main() {
    aylmao
    int n, K;
    cin >> n >> K;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    memset(cache, -1, sizeof(cache));

    cout << (Y([&](auto dp, int k, bool who) -> int {
        if(k < 0) return who;
        auto& ans = cache[k][who];
        if(~ans) return ans;
        ans = who^1;
        for(int i = 0; i < n; i++)
            if(dp(k-a[i], who^1) == who) ans = who;
        return ans;
    })(K, 1)? "First" : "Second");
    
    return 0;
}