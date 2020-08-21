/**
 🍪 the_hyp0cr1t3
 🍪 21.08.2020 15:30:26
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
#define int long long
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

const int N = 8;
const vector<vector<int>> perms{{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int32_t main() {
    aylmao
    vector<tuple<int, int, int>> A, ans;
    for(int i = 0; i < N; i++) {
        int x, y, z; cin >> x >> y >> z;
        A.pb(x, y, z);
    }

    auto dist = [](const auto& a, const auto& b) {
        auto [x1, y1, z1] = a;
        auto [x2, y2, z2] = b;
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
    };

    auto Try = [&](vector<tuple<int, int, int>> v) {
        vector<int> a;
        for(int i = 1; i < sz(v); i++) 
            a.pb(dist(v[0], v[i]));
        sort(all(a));
        if(!a[0] or a[0] != a[1] or a[1] != a[2] or a[2] != a[0])
            return;
        if(a[3] != 2*a[0] or a[4] != 2*a[0] or a[5] != 2*a[0] or a[6] != 3*a[0])
            return;
        ans = v;
    };

    Y([&](auto self, int dim, vector<tuple<int, int, int>> v) -> void {
        if(!dim) return Try(v);
        auto [a, b, c] = v[dim-1];
        array t{a, b, c};
        for(int i = 0, j; i < 6; i++) {
            v[dim-1] = {t[perms[i][0]], t[perms[i][1]], t[perms[i][2]]};
            for(j = dim; j < N; j++)
                if(v[dim-1] == v[j]) break; 
            if(j == N) self(dim-1, v);
        }
    })(N, A);

    if(ans.empty()) return cout << "NO", 0;

    cout << "YES" << endl;
    for(int i = 0; i < N; i++)
        apply([](const auto&... args){ ((cout << args << " "), ...); }, ans[i]), cout << endl;
    return 0;
}