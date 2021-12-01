/**
 🍪 the_hyp0cr1t3
 🍪 01.12.2021 21:46:49
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    const array dx{1, 0, -1, 0};
    const array dy{0, 1, 0, -1};

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, lx, ly, n, m;
        cin >> n >> m;
        vector<string> a(n);
        for(auto& x: a) cin >> x;

        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                if(a[i][j] == 'L')
                    lx = i, ly = j;

        vector<vector<int>> ans(n, vector<int>(m)), vis(n, vector<int>(m));
        auto bounds = [&](int x, int y) {
            return (0 <= x and x < n and 0 <= y and y < m and a[x][y] == '.' and !vis[x][y]);
        };

        auto valid = [&](int x, int y, int px, int py) {
            if(!bounds(x, y)) return false;
            int cnt = 0;
            for(int z = 0; z < 4; z++) {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if(bounds(nx, ny) and !(nx == px and ny == py))
                    cnt++;
            }
            return cnt <= 1;
        };

        auto dfs = Y([&](auto dfs, int cx, int cy, int px, int py) -> void {
            if(!valid(cx, cy, px, py)) return;
            ans[cx][cy] = true;
            vis[cx][cy] = true;
            for(int z = 0; z < 4; z++) {
                int nx = cx + dx[z];
                int ny = cy + dy[z];
                if(!(nx == px and ny == py))
                    dfs(nx, ny, cx, cy);
            }
        });

        for(int z = 0; z < 4; z++) {
            int cx = lx + dx[z];
            int cy = ly + dy[z];
            dfs(cx, cy, lx, ly);
        }

        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                if(ans[i][j]) a[i][j] = '+';

        for(auto& x: a)
            cout << x << '\n';
    }();

} // ~W