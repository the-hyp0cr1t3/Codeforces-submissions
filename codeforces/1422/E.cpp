/**
 🍪 the_hyp0cr1t3
 🍪 05.10.2020 10:39:26
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

string f(const string& s) {
    if(sz(s) <= 10) {
        string t = s; reverse(all(t));
        return t;
    }
    string t = s.substr(sz(s)-5); reverse(all(t));
    string u = s.substr(0, 2); reverse(all(u));
    return t + "..." + u;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; string s;
    cin >> s; n = sz(s);
    reverse(all(s));
    
    vector<pair<int, string>> ans;
    ans.reserve(n);

    string res;
    vector<pair<char, int>> stack;
    bool take = true;

    auto remove = [&]() {
        assert(!stack.empty() and !res.empty());
        if(!--stack.back().second) stack.pop_back();
        res.pop_back();
    };

    auto add = [&](char c) {
        if(!stack.empty() and c == stack.back().first) stack.back().second++;
        else stack.pb(c, 1);
        res += c;
    };

    for(i = 0; i < n; i++) {
        if(take and !stack.empty() and s[i] == stack.back().first
            and (sz(stack) == 1 or s[i] > stack[sz(stack)-2].first))
            remove(), take = false;
        else
            add(s[i]), take = true;
        ans.pb(sz(res), f(res));
    }

    reverse(all(ans));
    for(auto& [x, y]: ans) cout << x << ' ' << y << '\n';
}