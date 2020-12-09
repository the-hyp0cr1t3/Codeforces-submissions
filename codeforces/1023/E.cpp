/**
 🍪 the_hyp0cr1t3
 🍪 09.12.2020 19:52:08
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb push_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n; string left, right;
    cin >> n;
    
    auto valid = [n](int x, int y) { return 0 <= min(x, y) and max(x, y) < n; };
    auto query = [n](int x, int y, bool z = 0) {
        array<pair<int, int>, 2> A;
        A[0] = {x+1, y+1};
        A[1] = z? pair{n, n} : pair{1, 1};
        sort(all(A));
        cout << "? " << A[0].first << ' ' << A[0].second << ' ';
        cout << A[1].first << ' ' << A[1].second << endl;
        string s; cin >> s;
        return s == "YES";
    };

    for(i = j = 0; i+j < n-1; ) {
        if(query(i, j+1, true))
            left.pb('R'), j++;
        else left.pb('D'), i++;
    }

    for(i = j = n-1; i+j > n-1; ) {
        if(query(i-1, j))
            right.pb('D'), i--;
        else right.pb('R'), j--;
    } reverse(all(right));

    cout << "! " << left << right << endl;
} // ~W 