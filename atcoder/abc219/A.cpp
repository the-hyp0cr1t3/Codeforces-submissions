/**
 🍪 the_hyp0cr1t3
 🍪 18.09.2021 17:30:44
**/
#ifdef W
    #include <k_II.h>
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
    int i, n;
    cin >> n;
    if(n < 40)
        cout << 40 - n;
    else if(n < 70)
        cout << 70 - n;
    else if(n < 90)
        cout << 90 - n;
    else
        cout << "expert";
} // ~W