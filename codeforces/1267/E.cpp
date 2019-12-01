#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(a) a.begin(),a.end()
#define s second
#define f first
#define pb push_back
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
vector<vector<int>> mat; 
int32_t main() {
    IOS;
    int i, j, n, m;
    cin >> n >> m;
    mat.resize(m, vector<int>(n));
    vector<int> ans(m);
    iota(all(ans), 0);
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];
    for(i = 0; i < n-1; i++) {
        int sum = 0;
        vector<pii> diffs(m);
        vector<int> res;
        for(j = 0; j < m; j++) {
            diffs[j] = {mat[j][i]-mat[j][n-1], j};
            sum += mat[j][i]-mat[j][n-1];
        }
        sort(all(diffs));
        j = 0;
        while (j < m and sum < 0) {
            res.pb(diffs[j].s);
            sum -= diffs[j].f;
            j++;
        }
        if (res.size() < ans.size())
            ans = res;
    }
    cout << ans.size() << endl;
    for (auto& x: ans) 
        cout << x+1 << " ";
    return 0;
}