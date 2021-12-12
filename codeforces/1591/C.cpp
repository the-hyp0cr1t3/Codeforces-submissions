/**
 🍪 the_hyp0cr1t3
 🍪 12.12.2021 20:55:36
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
        int i, n, k;
        cin >> n >> k;
        vector<int> a, b;
        for(i = 0; i < n; i++) {
            int x; cin >> x;
            if(x > 0) a.push_back(x);
            if(x < 0)b.push_back(-x);
        }

        R::sort(a);
        R::sort(b);

        array<int64_t, 2> ans1{}, ans2{};
        for(auto _: {0, 1}) {
            n = a.size();
            deque<array<int64_t, 2>> q;
            q.push_back({0, 0});
            for(i = 1; i <= n; i++) {
                while(!q.empty() and i - q.front()[1] > k)
                    q.pop_front();
                int64_t val = q.front()[0] + a[i - 1] * 2;
                ans1[0] = val;
                ans1[1] = q.front()[0] + a[i - 1];
                while(!q.empty() and q.back()[0] >= val)
                    q.pop_back();
                q.push_back({val, i});
            }
            swap(a, b);
            swap(ans1, ans2);
        }

        cout << min(ans1[0] + ans2[1], ans1[1] + ans2[0]) << '\n';
    }();

} // ~W