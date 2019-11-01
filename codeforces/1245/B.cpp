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
const int N = 100 + 5;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, a, b, c, win;
        string s, res = "";
        char ans[N];
        cin >> n >> a >> b >> c >> s;
        win = n&1? n/2 + 1 : n/2;
        for(i = 0; i < n; i++) {
            switch(s[i]) {
                case 'R': {
                    if(b) 
                        b--, win--, res += "P";
                    else
                        res += "1";
                    break;
                }
                case 'P': {
                    if(c) 
                        c--, win--, res += "S";
                    else
                        res += "1";
                    break;
                }
                case 'S': {
                    if(a) 
                        a--, win--, res += "R";
                    else
                        res += "1";
                    break;
                }
            }
        }
        if (win <= 0) {
            for(i = 0; i < n; i++) {
                if (res[i] == '1') {
                    if (a)
                        ans[i] = 'R', a--;
                    else if (b)
                        ans[i] = 'P', b--;
                    else
                        ans[i] = 'S', c--;
                }
                else
                    ans[i] = res[i];
            }
            
            cout << "YES" << endl;
            for(i = 0; i < n; i++) {
                cout << ans[i];
            }
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
