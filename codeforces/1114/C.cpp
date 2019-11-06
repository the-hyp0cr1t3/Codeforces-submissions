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

using namespace std;
const int N = 1e5 + 5;

map<int, int> factorize(int x)
{
    int n = x;
    map<int, int> m;
    for(int i = 2; i*i <= n and x > 1; ++i)
        while(x % i == 0)
            m[i]++, x /= i;
    if(x > 1)
        m[x]++;
    return m;
}

int32_t main() {
    IOS;
    int i, n, b;
    int ans = DESPACITO;
    cin >> n >> b;
    map <int,int> m = factorize(b);
    for (auto& [k, v]: m) {
        int cnt = 0, p = k;
        while (p <= n) {
            cnt += n/p;
            if (p <= n/k)
                p *= k;
            else
                break;
        }
        ans = min(ans, cnt/v);
    }
    cout << ans;
    return 0;
}
