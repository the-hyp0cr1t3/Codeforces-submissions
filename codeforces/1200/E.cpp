#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define sz(x) (int)(x).size()
#define max(a,b) (a>b?a:b)
string word, ans;

vector<int> pi;

void generate_pi(string s) {
    int i, j, n, m, cnt = 0;
    n = sz(s);
    pi.resize(n);
    pi[0] = 0;
    for(i = 1, j = 0; i < n; i++) {
        if (s[i] == s[j])
            pi[i] = pi[i-1] + 1, j++;
        else {
            while(j and s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
    }
}

int KMPrefixSearch(string text, string ptrn, string delim = "#") {
    string str = ptrn + delim + text;
    generate_pi(str);
    return pi[sz(str)-1];
}

int32_t main() {
    IOS;
    int i, t, n, m;
    cin >> t >> ans;
    while (--t) {
        cin >> word;
        n = sz(ans), m = sz(word);
        int len = KMPrefixSearch(ans.substr(max(0, n-m)), word);
        ans += word.substr(len);
    }
    cout << ans;
    return 0;
}