/**
 🍪 thew6rst
 🍪 07.09.2020 09:26:48
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define endl '\n'
#define pb emplace_back
// #define int int64_t
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e5 + 5;

int the_real_main() {
    int i, j, n, k, both = 0, one = 0, zero = 0; string s;
    cin >> n >> k >> s;
    vector<int> cnt(2);

    auto Try = [&](int z, char cur) {        
    	set<char> s1{cur};
        for(i = z; i < n; i+=k) 
            s1.insert(s[i]);
        s1.erase('?');
        return sz(s1) < 2;
    };

    for(j = 0; j < k; j++) {
        if(s[j] == '?') {
            bool x = Try(j, '0'), y = Try(j, '1');
            if(x and y) both++;
            else if(x) zero++;
            else if(y) one++;
            else return cout << "NO" << endl, 0;            
        }
        else {
            cnt[s[j]-'0']++;
            if(!Try(j, s[j])) return cout << "NO" << endl, 0;            
        }
    }
    if(cnt[1] > k/2 or cnt[0] > k/2) return cout << "NO" << endl, 0;
    if(cnt[0] + zero > k/2 or cnt[1] + one > k/2) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    return 0;
}

int32_t main() {
    aylmao
    int Q; for(cin >> Q; Q; Q--) the_real_main();
    return 0;
}