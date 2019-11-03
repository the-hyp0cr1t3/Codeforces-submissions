#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
//#define long int64_t
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
#define int long long

using namespace std;
const int N = 1e5 + 5;

int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, free = 0, bad = -1;
        cin >> n;
        deque<int> base3;
        base3.push_front(n%3);
        while (n/=3)
            base3.push_front(n%3);
        i = 0;
        for (auto& x: base3) {
            if (x == 0)
                free = i;
            if (x == 2) {
                bad = i;
                break;
            }
            i++;
        }
        if (bad != -1) {
            if (!free) {
                for (auto& x: base3) 
                    x = 0;
                base3.push_front(1);
            }
            else {
                base3[free] = 1;
                i = 0;
                for(auto& x: base3) {
                    if (i > free) x = 0;
                    i++;
                }
            }
        }
        n = 0, i = 1;
        reverse(base3.begin(), base3.end());
        for(auto& x: base3)
            n += i*x, i *= 3;
        cout << n << endl;
    }
    return 0;
}
