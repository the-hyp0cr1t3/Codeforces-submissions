/**
 🍪 the_hyp0cr1t3
 🍪 11.12.2021 15:40:56
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

    int tests; cin >> tests;
    while(tests--) []() {
        int i, j, n;
        cin >> n;
        vector<int> A(n), B(n), a(n), b(n);
        for(auto& x: A) cin >> x;
        for(auto& x: B) cin >> x;

        iota(a.begin(), a.end(), 0);
        iota(b.begin(), b.end(), 0);

        R::sort(a, [&](int x, int y) {
            return A[x] > A[y];
        });
        R::sort(b, [&](int x, int y) {
            return B[x] > B[y];
        });


        string ans(n, '0');
        int cura = 0, curb = 0;
        ans[a[0]] = ans[b[0]] = '1';

        queue<int> q;
        q.push(a[0]); q.push(b[0]);

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            while(cura < n and A[a[cura]] > A[cur]) {
                if(ans[a[cura]] == '0')
                    ans[a[cura]] = '1', q.push(a[cura]);
                cura++;
            }
            while(curb < n and B[b[curb]] > B[cur]) {
                if(ans[b[curb]] == '0')
                    ans[b[curb]] = '1', q.push(b[curb]);
                curb++;
            }
        }

        cout << ans << '\n';
    }();

} // ~W