/**
 🍪 the_hyp0cr1t3
 🍪 08.08.2021 17:33:40
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i = 1, j = 1, n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 2>> a(k);
    map<int, int> xcoords, ycoords;
    for(auto& [x, y]: a) {
        cin >> x >> y;
        xcoords[x]; ycoords[y];
    }

    for(auto& [x, y]: xcoords)
        y = i++;
    for(auto& [x, y]: ycoords)
        y = j++;

    for(auto& [x, y]: a) {
        cout << xcoords[x] << ' ' << ycoords[y] << '\n';
    }

} // ~W