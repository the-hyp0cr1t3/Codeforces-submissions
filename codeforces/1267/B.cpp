#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) (int)(x).size()

int32_t main() {
    int i, j = 0, n;
    string s;
    cin >> s;
    n = sz(s);
    vector<pair<char, int>> cnt;
    cnt.pb({s[0], 1});
    for(i = 1; i < n; i++) {
        if (s[i] == s[i-1])
            cnt[j].second++;
        else
            cnt.pb({s[i], 1}), j++;
    }
    if ((sz(cnt) & 1) == 0 or cnt[sz(cnt)/2].second < 2)
        return cout << 0, 0;
    int mid = sz(cnt)/2;
    int p = mid + 1;
    while (p < sz(cnt)) {
        if (cnt[p].second == 1 and cnt[2*mid-p].second == 1)
            return cout << 0, 0;
        if (cnt[p].first != cnt[2*mid-p].first)
            return cout << 0, 0;
        p++;
    }
    return cout << cnt[mid].second + 1, 0;
}
