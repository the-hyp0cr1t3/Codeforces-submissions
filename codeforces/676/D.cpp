/**
 🍪 the_hyp0cr1t3
 🍪 19.08.2020 16:17:16
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
// #define int long long
#define endl '\n'
#define pb emplace_back
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5+5;
const array dx{0, -1, 0, 1};
const array dy{-1, 0, 1, 0};
const vector<string> block{"****", "<^>v<^>", "-|-|-", "LURD", "++++"};

int32_t main() {
    aylmao
    int i, j, k, n, m, stx, sty, enx, eny;
    cin >> n >> m;
    vector<vector<pii>> a(n, vector<pii>(m));
    for(i = 0; i < n; i++) {
        string s; cin >> s;
        for(j = 0; j < m; j++) {
            for(k = 0; k < 5; k++) { 
                auto it = block[k].find(s[j]);
                if(it != string::npos) a[i][j] = {k, it};
            }
        }
    }
    cin >> stx >> sty >> enx >> eny;
    stx--; sty--; enx--; eny--;
    if(stx == enx and sty == eny) return cout << 0, 0;

    vector<vector<vector<int>>> d(4, vector<vector<int>>(n, vector<int>(m))); 

    auto check = [&](int dir, int o, int x, int y) {
        dir %= 4; o %= 4;
        int res = a[x][y].second + o;
        if(a[x][y].first == 0) return false;
        else if(a[x][y].first == 1) return res % 4 == dir;
        else if(a[x][y].first == 2) return res % 4 == dir or (res+2)%4 == dir;
        else if(a[x][y].first == 3) return res % 4 != dir;
        else return true;
    };
    
    auto ans = [&]() {
        queue<tuple<int, int, int>> q;
        q.push(make_tuple(0, stx, sty));
        d[0][stx][sty] = 1;
        while(!q.empty()) {
            auto [o, curx, cury] = q.front();
            q.pop();
            if(!d[(o+1)%4][curx][cury]) {
                d[(o+1)%4][curx][cury] = d[o][curx][cury] + 1;
                q.push({(o+1)%4, curx, cury});
            }
            for(int z = 0; z < 4; z++) {
                int x = curx + dx[z];
                int y = cury + dy[z];
                if(x < 0 or x >= n or y < 0 or y >= m) continue;
                if(!check(z, o, curx, cury) or !check(z+2, o, x, y)) continue;
                if(!d[o][x][y]) {
                    d[o][x][y] = d[o][curx][cury] + 1;
                    q.push({o, x, y});
                }
            }
        }
        int mn = INF;
        for(int o = 0; o < 4; o++) 
            if(d[o][enx][eny]) chmin(mn, d[o][enx][eny]);
        return mn;
    }();
    
    cout << (ans == INF? -1 : ans-1);
    return 0;
}