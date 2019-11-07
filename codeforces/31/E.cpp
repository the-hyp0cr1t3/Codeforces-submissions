#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 100000007  //1e8 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
#define PI acos(-1);
#define E 998244353
#define ins insert
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define int long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 20;
int n;
string s;
int cache[2*N][N][N], path[2*N][N][N], power10[N];

int dp (int idx, int a, int b) {
    if (idx == 2*n+1)
        return 0;
    int &ans = cache[idx][a][b];
    if (ans != -1)
        return ans;
    if (a == n) {
        ans = power10[n - 1 - b] * (s[idx - 1] - '0')+ dp(idx+1, a, b+1);
        path[idx][a][b] = 2;
    }
    else if (b == n) {
        ans = power10[n - 1 - a] * (s[idx - 1] - '0') + dp(idx+1, a+1, b);
        path[idx][a][b] = 1;
    }
    else{
        int x, y;
        if (!idx)
            x = dp(idx+1, a, b), y = dp(idx+1, a, b);
        else {
            x = power10[n - 1 - a] * (s[idx - 1] - '0') + dp(idx+1, a+1, b);
            y = power10[n - 1 - b] * (s[idx - 1] - '0') + dp(idx+1, a, b+1);
        }
        ans  = max(x, y);
        if(x > y)
            path[idx][a][b] = 1;
        else
            path[idx][a][b] = 2;
    }
    return ans;
}

int32_t main() {
    IOS;
    int i, res, j, k;
    cin >> n >> s;
    memset(cache, -1, sizeof(cache));
    memset(path, -1, sizeof(path));
    power10[0] = 1;
    for(i = 1; i <= 18; i++) 
        power10[i] = power10[i-1]*10;
    res = dp(0,0,0);
    for(i = 0, j = 0, k = 0; i <= 2*n; i++) {
        if (path[i][j][k] == 1) 
            cout << "H", j++;
        else if (path[i][j][k] == 2)
            cout << "M", k++;
    }
    return 0;
}
