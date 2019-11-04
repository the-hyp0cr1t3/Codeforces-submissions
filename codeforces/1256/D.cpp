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
#define ll long long

using namespace std;
const int N = 1e6 + 5;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, last = -1;
        ll k;
        string s;
        cin >> n >> k >> s;
        for(i = 0; i < n; i++) {
            if (s[i]=='0') {
                if (last == -1)
                    continue;
                if (k) {
                    if (k >= i - last) {
                        swap(s[i], s[last]);
                        k-= (i-last);
                        while(s[last] == '0' and last < i)
                            last++;
                    }
                    else {
                        swap (s[i], s[i-k]);
                        k = 0;
                    }
                }
                else 
                    break;
            }
            else 
                if (last == -1) last = i;
        }
        cout << s << endl;
    }
    return 0;
}
