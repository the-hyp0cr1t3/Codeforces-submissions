/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 20:27:19
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
    const int N = 1e6 + 5;
    array<int64_t, N> have{}, ans{};

    int i, j, n, res = 0;
    cin >> n;
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        have[x] = true;
    }

    for(i = N - 1; i; i--) {
        int cnt = 0;
        for(j = i; j < N; j += i) {
            cnt += have[j];
            ans[i] -= ans[j];
        }
        ans[i] += 1LL * cnt * (cnt - 1) / 2;
        if(ans[i] > 0 and !have[i]) {
            have[i] = true;
            ans[i] += cnt;
        }
        assert(ans[i] >= 0);
        res += have[i];
    }

    cout << res - n;

} // ~W