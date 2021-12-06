/**
 🍪 the_hyp0cr1t3
 🍪 07.12.2021 00:03:05
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
    const int LG = 20;

    auto xor0 = [](const vector<int>& a) {
        map<int, int> pref;
        pref[0] = -1;
        int cur = 0, res = 0;
        for(int i = 0; i < a.size(); i++) {
            cur ^= a[i];
            if(!pref.count(cur))
                pref[cur] = i;
            else
                res = max(res, i - pref[cur]);
        }

        return res;
    };

    int i, j, k, b, n, ans = 0;
    cin >> n;
    vector<int> A(n), a(n);
    for(auto& x: A) cin >> x;

    for(b = LG - 1; ~b; b--) {
        for(i = 0; i < n; ) {
            for(; i < n and ~A[i] >> b & 1; i++);
            if(i == n) break;
            for(j = i; j < n and A[j] >> b & 1; j++);
            for(auto _: { i, i + 1 }) {
                vector<int> sub;
                sub.reserve(j - i >> 1);
                for(k = _; k + 1 < j; k += 2)
                    sub.push_back(a[k] ^ a[k + 1]);
                ans = max(ans, xor0(sub) * 2);
            }
            for(; i < j; i++) a[i] ^= A[i] & (1 << b);
        }
    }

    cout << ans;
} // ~W