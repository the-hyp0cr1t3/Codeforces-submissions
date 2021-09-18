/**
 🍪 the_hyp0cr1t3
 🍪 18.09.2021 17:33:39
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
    int n; string s; array<int, 26> pos;
    cin >> s >> n;
    vector<string> a(n);
    for(auto& x: a) cin >> x;

    for(int i = 0; i < 26; i++)
        pos[s[i] - 'a'] = i;

    sort(all(a), [&](const auto& A, const auto& B) {
        for(int i = 0; i < min(sz(A), sz(B)); i++)
            if(A[i] ^ B[i]) return pos[A[i] - 'a'] < pos[B[i] - 'a'];
        return sz(A) < sz(B);
    });

    for(auto& x: a) cout << x << '\n';
} // ~W