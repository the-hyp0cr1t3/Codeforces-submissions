#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(a) a.begin(),a.end()
#define pb push_back
#define sz(x) (int)(x).size()
#define INF 2000000
const int N = 55 + 5;

int n, m;
int a[N][N], vis[N][N];
vector<tuple<int, int, int, int>> counts;

int dfs1(int x, int y, int c) {
    vis[x][y] = c;
    int cnt;
    if (x == 1 or x == n or y == 1 or y == m)
        cnt = -INF;
    else
        cnt = 1;
    for(int i = -1; i < 2; i++) 
        for(int j = -1; j < 2; j++)
            if (abs(i) + abs(j) == 1 and !vis[x+i][y+j] and a[x+i][y+j]) cnt += dfs1(x+i, y+j, c);
    return cnt;
}

void dfs2(int x, int y, int c) {
    vis[x][y] = -1;
    a[x][y] = 0;
    for(int i = -1; i < 2; i++) 
        for(int j = -1; j < 2; j++)
            if (abs(i) + abs(j) == 1 and vis[x+i][y+j] == c) dfs2(x+i, y+j, c);
}

int32_t main() {
    IOS;
    int i, j, k, d, col = 1;
    char c;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) 
            cin >> c, a[i][j] = c == '.'? 1 : 0, vis[i][j] = 0;
    }
        
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            d = 0;
            if (a[i][j] and !vis[i][j]) 
                d = dfs1(i, j, col);
            if (d > 0) counts.pb(make_tuple(d, col++, i, j));
        }
    }
    sort(all(counts), [] (tuple<int, int, int, int> p, tuple<int, int, int, int> q) { 
        return get<0>(p) > get<0>(q); 
    });
    
    int ans = 0;
    for(i = k; i < sz(counts); i++) {
        ans += get<0>(counts[i]);
        dfs2(get<2>(counts[i]), get<3>(counts[i]), get<1>(counts[i]));
    }

    cout << ans << endl;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) 
            cout << (a[i][j]? '.' : '*');
        cout << endl;
    }
    return 0;
}