/**
 🍪 thew6rst
 🍪 09.09.2020 16:05:33
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
// #define int int64_t
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
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

const int N = 2e5 + 5;
map<char, char> mp{{'L', 'U'}, {'R', 'D'}, {'U', 'L'}, {'D', 'R'}};

int the_real_main() {
    int i, j, n, m;
    cin >> n >> m;
    vector<string> a, black;
    if(n > m) {
        a.assign(m, string(n, 0));
        black.assign(m, string(n, 0));
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                cin >> black[j][i];
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                cin >> a[j][i], a[j][i] = mp[a[j][i]];
        swap(n, m);
    } else {
        a.assign(n, string(m, 0));
        black.assign(n, string(m, 0));
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                cin >> black[i][j];
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                cin >> a[i][j];
    }

    vector<vector<int>> cycles;
    vector<vector<int>> cycleid(n, vector<int>(m));
    vector<vector<int>> cyclesz(n, vector<int>(m));
    vector<vector<int>> mod(n, vector<int>(m));

    auto get = [&](int x, int y) {
        if(a[x][y] == 'L') y--;
        else if(a[x][y] == 'R') y++;
        else if(a[x][y] == 'U') x--;
        else if(a[x][y] == 'D') x++;
        else assert(false);
        return pii(x, y);
    };

    auto dfs = Y([&](auto self, int x, int y, int depth = 1) -> void {
        cyclesz[x][y] = -depth;
        auto [p, q] = get(x, y);
        if(cyclesz[p][q] < 0) {
            cyclesz[x][y] = depth + cyclesz[p][q] + 1;
            cycleid[x][y] = sz(cycles);
            cycles.pb(vector<int>(cyclesz[x][y]));
            if(black[x][y] == '0') cycles.back()[0] = 1;
            return;
        }
        if(!cyclesz[p][q])
            self(p, q, ++depth);
        cyclesz[x][y] = cyclesz[p][q];
        cycleid[x][y] = cycleid[p][q];
        mod[x][y] = (mod[p][q] + 1) % cyclesz[x][y];
        if(black[x][y] == '0') cycles[cycleid[x][y]][mod[x][y]] = 1;
    });

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(!cyclesz[i][j]) dfs(i, j);

    int total = 0, blacks = 0;
    for(auto& c: cycles) {
        total += sz(c);
        blacks += accumulate(all(c), 0);
    }

    cout << total << " " << blacks << '\n';
    return 0;
}

int32_t main() {
    aylmao int Q; for(cin >> Q; Q; Q--) the_real_main();
}