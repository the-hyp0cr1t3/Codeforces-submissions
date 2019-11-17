#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define min(a,b) (a<b?a:b)
#define LOW 0
#define UP 1
const int N = 1e5 + 5;
int cache[N][2];
string s;

int dp (int idx, bool opt) {
    if (idx == 0)
        return 0;
    int &ans = cache[idx][opt];
    if (ans != -1)
        return ans;
    if (opt == UP)
        ans = dp(idx-1, UP) + (islower(s[idx-1])? 1 : 0);
    else
        ans = min(dp(idx-1, LOW), dp(idx-1, UP)) + (isupper(s[idx-1])? 1 : 0);
    return ans;
}

int32_t main() {
    IOS;
    memset(cache, -1, sizeof(cache));
    cin >> s;
    int n = (int) s.length();
    cout << min(dp(n, LOW), dp(n, UP));
    return 0;
}