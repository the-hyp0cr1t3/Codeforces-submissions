#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rsz resize
#define pb push_back
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
map <int,int> mp;
vector<pii> cnt; 
vector<vector<int>> mat;

void work (int rows, int cols) {
    mat.rsz(rows, vector<int> (cols));
    int cur = 0, filled = 0;
    for (int i = sz(cnt)-1; i >= 0; i--) {
        for(int j = 0; j < min(rows, cnt[i].ff); j++, cur++) {
            if (filled == rows * cols) return;
            mat[cur%rows][(cur%rows+cur/rows)%cols] = cnt[i].ss, filled++;
        }
    }
}

int32_t main() {
    IOS;
    int i, n, a, r;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
    }
    for (auto& x: mp) 
        cnt.pb({x.ss, x.ff});
    sort(all(cnt));
    int m = sz(cnt);
    vector<int> pref(m+1);
    for(i = 1; i <= m; i++) 
        pref[i] = pref[i-1] + cnt[i-1].ff;
    int cur = m, R, ans = 0;
    for(r = 700; r > 0; r--) {
        while(cur > 0 and cnt[cur-1].ff > r) cur--;
        int used = (m - cur) * r + pref[cur];
        if (used >= r*r) {
            if (used/r*r > ans)
                ans = used/r*r, R = r;
        }
    }
    cout << ans << endl;
    cout << R << " " << ans/R << endl;
    work(R, ans/R);
    for (auto& x: mat) { 
        for (auto& y: x) 
            cout << y << " ";
        cout << endl;
    }
    return 0;
}