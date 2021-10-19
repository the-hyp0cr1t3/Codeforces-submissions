// not mine
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;
#define int long long
struct fenwick{
    int n;
    vector<int>v;
    void assign(int _n){
        n = _n;
        v.assign(n + 1, 0);
    }
    void update(int p){
        p++;
        for(int i = p; i > 0; i -= i&-i){
            v[i]++;
        }
    }
    int get(int p){
        p++;
        int res = 0;
        for(int i = p; i <= n; i += i&-i){
            res += v[i];
        }
        return res;
    }
};
main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    vector<int> q(k);
    for(int i = 0; i < k; i++) cin >> q[i];
    fenwick fen[m];
    for(int i = 0; i < m; i++){
        fen[i].assign(n);
    }
    for(int j = 0; j < m; j++){
        for(int i = n - 1; i >= 0; i--){
            if(a[i][j] == 2) fen[j].update(i);
        }
    }
    function<int(int,int)> visit = [&](int x, int y){
        if(fen[y].get(x) == n - x) return y;
        if(a[x][y] == 1){
            fen[y].update(x);
            a[x][y] = 2;
            if(y + 1 == m) return y;
            return visit(x, y + 1);
        }
        else if(a[x][y] == 2){
            if(x + 1 == n) return y;
            return visit(x + 1, y);
        }
        else{
            fen[y].update(x);
            a[x][y] = 2;
            if(y - 1 == -1) return y;
            return visit(x, y - 1);
        }
    };
    for(int i = 0; i < k; i++){
        cout << visit(0, q[i] - 1) + 1 << " ";
    }
}