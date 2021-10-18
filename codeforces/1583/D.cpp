/**
 🍪 the_hyp0cr1t3
 🍪 19.10.2021 00:02:49
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, j, n;
    cin >> n;

    vector<int> ans(n);
    for(i = n; i > 1; i--) {
        cout << '?';
        for(j = 1; j < n; j++)
            cout << ' ' << i;
        cout << ' ' << 1 << endl;
        int k; cin >> k;
        if(k) break;
    }

    ans[n - 1] = i;

    for(i = 1; i <= n; i++) {
        if(i == ans.back()) continue;
        cout << '?';
        for(j = 1; j < n; j++)
            cout << ' ' << ans.back();
        cout << ' ' << i << endl;
        int k; cin >> k;
        ans[k - 1] = i;
    }

    cout << '!';
    for(i = 0; i < n; i++)
        cout << ' ' << ans[i];
    cout << endl;
} // ~W