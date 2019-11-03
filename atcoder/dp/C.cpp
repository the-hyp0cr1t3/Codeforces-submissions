//https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
//#define long int64_t
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max3(a,b,c) (a>=b and a>=c ? a : b>=c and b>=a ? b : c)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 2e9
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;
const int N = 1e5 + 5;
ll a[N], b[N], c[N], cache[N][3];

ll dp (int idx, int opt) {
    if (idx == 0)
        return 0;
    ll &ans = cache[idx][opt];
    if (ans != -1) 
        return ans;
    else {
        switch(opt) {
            case 0:
                ans = max(dp(idx-1, 1), dp(idx-1, 2)) + a[idx];
                break;
            case 1:
                ans = max(dp(idx-1, 0), dp(idx-1, 2)) + b[idx];
                break;
            case 2:
                ans = max(dp(idx-1, 0), dp(idx-1, 1)) + c[idx];
                break;
        }
        //cerr << "cache[" << idx << "][" << opt << "] is " << cache[idx][opt] << endl;
        return ans;
    }
}

int main() {
    int i, n;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(i = 1; i <= n; i++) 
        cin >> a[i] >> b[i] >> c[i];
    cout << max(dp(n, 0), max(dp(n, 1), dp(n, 2)));
    return 0;
}