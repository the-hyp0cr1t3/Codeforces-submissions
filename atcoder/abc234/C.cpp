/**
 🍪 the_hyp0cr1t3
 🍪 08.01.2022 17:35:01
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

    int64_t n;
    cin >> n;

    const int LG = 64;
    string ans(LG, '0');
    for(int i = 0; i < LG; i++)
        if(n >> i & 1) ans[i] += 2;

    while(ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());

    cout << ans;
} // ~W