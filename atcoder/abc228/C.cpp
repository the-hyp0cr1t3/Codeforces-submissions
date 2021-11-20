/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2021 17:41:14
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, j, n, k;
    cin >> n >> k;
    vector<int> ans(n);
    vector<array<int, 2>> a(n);
    for(i = 0; i < n; i++) {
        a[i][1] = i;
        for(j = 0; j < 3; j++) {
            int x; cin >> x;
            a[i][0] += x;
        }
    }

    sort(a.rbegin(), a.rend());

    for(i = 0; i < n; i++) {
        if(a[i][0] + 300 >= a[k - 1][0])
            ans[a[i][1]] = true;
    }

    for(i = 0; i < n; i++)
        cout << (ans[i]? "Yes" : "No") << '\n';

} // ~W