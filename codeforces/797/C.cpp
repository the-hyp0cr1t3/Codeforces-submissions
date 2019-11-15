#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define sz(x) (int)(x).size()
#define lb lower_bound
int32_t main() {
    IOS;
    int i;
    string str, ans;
    cin >> str;
    stack <char> s;
    map <char,int> freq;
    for(i = 0; i < sz(str); i++)
        freq[str[i]]++;
    for(i = 0; i < sz(str); i++) {
        s.push(str[i]);
        if (!--freq[str[i]])
            freq.erase(str[i]);
        while (!s.empty() and freq.lb(s.top()) == freq.begin())
            ans += s.top(), s.pop();
    }
    while (!s.empty())
        ans += s.top(), s.pop();
    cout << ans;
    return 0;
}
