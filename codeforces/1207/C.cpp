#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
//#define long int64_t
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 1e14
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;
const int N = 2e5 + 5;
int n, a, b;
ll cache[N][2];
string s;

ll dp (int idx, int opt) {
    if (idx == 0)
        return (opt? (ll)DESPACITO : b);
    ll &ans = cache[idx][opt];
    if (ans != -1)
        return ans;
    if (!opt and (s[idx-1] == '1' or (idx < n and s[idx] == '1')))
        ans = DESPACITO;
    else if (opt)
        ans = min((dp(idx-1, 1) + a + b * 2), (dp(idx-1, 0) + 2 * a + b * 2));
    else
        ans = min((dp(idx-1, 0) + a + b), (dp(idx-1, 1) + 2 * a + b));
    return ans;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int i;
        memset(cache, -1, sizeof(cache));
        cin >> n >> a >> b >> s;
        cout << dp(n, 0) << endl;;
    }
    return 0;
}
