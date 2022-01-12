/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2022 15:27:25
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int N = 1e9;
    vector<int> a;
    for(int64_t i = 1; i * i <= N; i++)
        a.push_back(i * i);
    for(int64_t i = 1; i * i * i <= N; i++)
        a.push_back(i * i * i);

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, n;
        cin >> n;
        cout << R::upper_bound(a, n) - a.begin() << '\n';
    }();

} // ~W