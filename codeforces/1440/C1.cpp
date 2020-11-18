/**
 🍪 the_hyp0cr1t3
 🍪 18.11.2020 14:17:23
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

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

struct Point {
    int x, y;
    Point(int x = -1, int y = -1): x(x), y(y) {}
};

int simPforPolyphia() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }

    vector<array<Point, 3>> ans;
    ans.reserve(3*n*m);

    auto go = Y([&](auto self, const array<Point, 4>& points) -> void {
        vector<Point> one, zero;
        for(auto p: points) {
            if(a[p.x][p.y]) one.pb(p);
            else zero.pb(p);
        }
        if(sz(zero) == 4) {
        } else if(sz(one) >= 3) {
            array<Point, 3> tmp;
            for(int i = 0; i < 3; i++)
                tmp[i] = one[i], a[one[i].x][one[i].y] ^= 1;
            ans.pb(tmp);
            self(points);
        } else {
            array<Point, 3> tmp;
            for(int i = 0; i < 2; i++)
                tmp[i] = zero[i], a[zero[i].x][zero[i].y] ^= 1;
            tmp[2] = one[0]; a[one[0].x][one[0].y] ^= 1;
            ans.pb(tmp);
            self(points);
        }
    });

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m-1; j++) {
            array<Point, 4> tmp;
            tmp[0] = Point(i, j);
            tmp[1] = Point(i+1, j);
            tmp[2] = Point(i, j+1);
            tmp[3] = Point(i+1, j+1);
            go(tmp);
        }
    }

    assert(sz(ans) <= 3*n*m);
    cout << sz(ans) << '\n';
    for(auto& [p1, p2, p3]: ans) {
        cout << p1.x+1 << ' ' << p1.y+1 << ' ';
        cout << p2.x+1 << ' ' << p2.y+1 << ' ';
        cout << p3.x+1 << ' ' << p3.y+1 << '\n';
    }
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) simPforPolyphia();
} // ~W