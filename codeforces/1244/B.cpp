#include <bits/stdc++.h>
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
#define ll long long

using namespace std;
const int N = 1e5 + 5;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i = 1, first = 0, last = 0;
        bool flag = 0;
        string s;
        cin >> n >> s;
        for (char c: s) {
            if (c == '1') {
                last = i;
                if (!flag)
                    first = i, flag = 1;
            }
            i++;
        }
        if (!last)
            cout << n << endl;
        else
            cout << 2 * max(last, n - first + 1) << endl;
    }
    return 0;
}
