//https://atcoder.jp/contests/dp/tasks/dp_h
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define MOD 1000000007  //1e9 + 7
vector<vector<int>> mat, cache;

int dp (int x, int y) {
    if (!x or !y)
        return 0;
    if (!mat[x][y])
        return 0;
    int &ans = cache[x][y];
    if (ans != -1)
        return ans;
    ans = (dp(x-1, y) + dp(x, y-1)) % MOD;
    return ans;
}

int32_t main() {
    IOS;
    int i, h, w;
    cin >> h >> w;
    mat.resize(h+1, vector<int>(w+1));
    cache.resize(h+1, vector<int>(w+1, -1));
    cache[1][1] = 1;
    for(i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            char c;
            cin >> c;
            mat[i][j] = c == '.'? 1: 0;
        }
    }
    cout << dp(h, w);
    return 0;
}