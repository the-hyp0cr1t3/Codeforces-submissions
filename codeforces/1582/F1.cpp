/**
 🍪 the_hyp0cr1t3
 🍪 24.10.2021 16:16:40
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int N = 513;

    int i, n;
    cin >> n;

    array<int, N> dp;
    dp.fill(N);
    dp[0] = 0;
    while(n--) {
        int a; cin >> a;
        for(i = 0; i < N; i++)
            if(dp[i] < a) dp[i ^ a] = min(dp[i ^ a], a);
    }

    cout << N - ranges::count(dp, N) << '\n';
    for(i = 0; i < N; i++)
        if(dp[i] < N) cout << i << ' ';

} // ~W