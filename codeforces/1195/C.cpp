#include <bits/stdc++.h>
//#define long int64_t
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
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
int a[N], b[N], n;
ll cache[N][2];

ll dp (int idx, int opt) {
    if (idx == 0)
        return 0;
    ll &ans = cache[idx][opt];
    if (ans != -1)
        return ans;
    ans = max(dp(idx - 1, opt), dp(idx - 1, opt^1) + (opt? b[idx] : a[idx]));
    return ans;
}

int main() {
    int i;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    for(i = 1; i <= n; i++) 
        cin >> b[i];
    cout << max(dp(n, 0), dp(n, 1));
return 0;
}
