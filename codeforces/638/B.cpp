#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define rsz resize
#define sz(x) (int)(x).size()

int nxt[26], vis[26];

void dfs(int v) {
    vis[v] = 2;
    cout << (char) (v+'a');
    if (vis[nxt[v]] != 2 and nxt[v] != -1) dfs(nxt[v]);
}

int32_t main() {
    IOS;
    memset(nxt, -1, sizeof(nxt));
    int i, n;
    string s;
    cin >> n;
    auto a = [&] (int j) {return s[j]-'a';};
    while (n--) {
        cin >> s;
        for(i = 1; i < sz(s); i++) {
            vis[a(i)] = 1;
            nxt[a(i-1)] = a(i);
        }
        if (!vis[a(0)]) vis[a(0)] = -1;
    }
    for(i = 0; i < 26; i++) 
        if (vis[i] == -1) dfs(i);
    return 0;
}