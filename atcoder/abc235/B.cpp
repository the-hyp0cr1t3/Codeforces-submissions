/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 17:32:40
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

    int i, n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) cin >> x;

    for(i = 1; i < n; i++)
        if(a[i] <= a[i - 1]) break;

    cout << a[i - 1];

} // ~W