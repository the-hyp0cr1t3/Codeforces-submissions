/**
 🍪 the_hyp0cr1t3
 🍪 11.12.2021 15:56:48
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
        int i, j, k, n, a, b;
        cin >> n >> a >> b;
        if(abs(a - b) > 1)
            return cout << -1 << '\n', 0;
        vector<int> take, leave, ans(n);
        if(a > b) {
            int m = 2 * a + 1;
            if(m > n)
                return cout << -1 << '\n', 0;

            for(i = 0; i < m; i++)
                take.push_back(n - i);
            R::reverse(take);
            leave.resize(n - m);
            iota(leave.begin(), leave.end(), 1);
            R::reverse(leave);

            ans[0] = take[0];
            for(i = 1, j = m - 1, k = 1; i < j; i++, j--) {
                ans[k] = take[j];
                ans[k + 1] = take[i];
                k += 2;
            }

            for(i = 0; i < leave.size(); i++)
                ans[k++] = leave[i];

        } else if(a == b) {
            int m = 2 * a + 2;
            if(m > n)
                return cout << -1 << '\n', 0;

            take.resize(m);
            iota(take.begin(), take.end(), 1);
            leave.resize(n - m);
            iota(leave.begin(), leave.end(), m + 1);

            ans[0] = take[0];
            for(i = 1, j = m - 1, k = 1; i < j; i++, j--) {
                ans[k] = take[j];
                ans[k + 1] = take[i];
                k += 2;
            }
            ans[k++] = take[i];

            for(i = 0; i < leave.size(); i++)
                ans[k++] = leave[i];
        } else {
            int m = 2 * b + 1;
            if(m > n)
                return cout << -1 << '\n', 0;

            take.resize(m);
            iota(take.begin(), take.end(), 1);
            leave.resize(n - m);
            iota(leave.begin(), leave.end(), m + 1);

            ans[0] = take[m - 1];
            for(i = 0, j = m - 2, k = 1; i < j; i++, j--) {
                ans[k] = take[i];
                ans[k + 1] = take[j];
                k += 2;
            }

            for(i = 0; i < leave.size(); i++)
                ans[k++] = leave[i];
        }

        for(auto& x: ans)
            cout << x << ' ';
        cout << '\n';
        return 0;
    }();

} // ~W