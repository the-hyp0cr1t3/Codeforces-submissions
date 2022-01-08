/**
 🍪 the_hyp0cr1t3
 🍪 08.01.2022 17:38:39
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

    int i, n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;

    set<int> s;
    for(i = 0; i + 1 < k; i++)
        s.insert(a[i]);
    for(; i < n; i++) {
        s.insert(a[i]);
        while(s.size() > k) s.erase(s.begin());
        cout << *s.begin() << '\n';
    }


} // ~W