/**
 🍪 the_hyp0cr1t3
 🍪 18.11.2020 14:46:42
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
    int i, j, n, m; char c;
    cin >> n >> m;
    vector<vector<int>> a(min(n, m), vector<int>(max(n, m)));
    bool swp = n > m;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> c, (swp? a[j][i] : a[i][j]) = c - '0';
    if(swp) swap(n, m);

    vector<array<Point, 3>> ans;
    ans.reserve(n*m);

    auto normalize = [&](const array<Point, 4>& points) {
        int cnt = 0; array<Point, 3> tmp;
        for(int z = 0; z < 2; z++)
            if(a[points[z].x][points[z].y]) tmp[cnt++] = points[z];
        for(int z = 2; z < 4 and cnt < 3; z++)
            tmp[cnt++] = points[z];

        if(cnt < 3) return;
        ans.pb(tmp);
        for(auto& x: tmp)
            a[x.x][x.y] ^= 1;
    };

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


    for(i = 0; i < n-1; i += 2) {
        for(j = 0; j < m-2; j++) {
            array<Point, 4> tmp;
            tmp[0] = Point(i, j);
            tmp[1] = Point(i+1, j);
            tmp[2] = Point(i, j+1);
            tmp[3] = Point(i+1, j+1);
            normalize(tmp);
        }
        array<Point, 4> tmp;
        tmp[0] = Point(i, j);
        tmp[1] = Point(i+1, j);
        tmp[2] = Point(i, j+1);
        tmp[3] = Point(i+1, j+1);
        go(tmp);
    }

    for(i = n-2, j = 0; j < m-2; j++) {
        array<Point, 4> tmp;
        tmp[0] = Point(i, j);
        tmp[1] = Point(i+1, j);
        tmp[2] = Point(i, j+1);
        tmp[3] = Point(i+1, j+1);
        normalize(tmp);        
    }
    array<Point, 4> tmp;
    tmp[0] = Point(i, j);
    tmp[1] = Point(i+1, j);
    tmp[2] = Point(i, j+1);
    tmp[3] = Point(i+1, j+1);
    go(tmp);

    assert(sz(ans) <= n*m);
    cout << sz(ans) << '\n';
    for(auto& [p1, p2, p3]: ans) {
        if(swp) {
            swap(p1.x, p1.y);
            swap(p2.x, p2.y);
            swap(p3.x, p3.y);
        }
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