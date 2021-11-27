/**
 🍪 the_hyp0cr1t3
 🍪 27.11.2021 19:46:58
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

    string s;
    int i, n; int64_t k;
    cin >> s >> k;
    n = s.size();

    int cnt = count(s.begin(), s.end(), 'Y');
    vector<int> occ;
    vector<int64_t> pref, suf;
    occ.reserve(cnt);
    for(i = 0; i < n; i++) {
        if(s[i] == 'Y') {
            occ.push_back(i);
            pref.push_back(i + (pref.empty()? 0 : pref.back()));
            suf.push_back(n - 1 - i + (suf.empty()? 0 : suf.back()));
        }
    }

    auto get = [](const auto& v, int l, int r) {
        return v[r] - (l? v[l - 1] : 0);
    };

    auto check = [&](int x) {
        int64_t mn = 1e18;
        for(int m = x / 2, l = 0, r = x - 1; r < cnt; l++, m++, r++) {
            mn = min<int64_t>(mn,
                get(suf, l, m) - 1LL * (m - l + 1) * (n - 1 - occ[m])
                - 1LL * (m - l + 1) * (m - l) / 2
                + get(pref, m, r) - 1LL * (r - m + 1) * occ[m]
                - 1LL * (r - m + 1) * (r - m) / 2
            );
        }
        return mn <= k;
    };

    int lo = 1, hi = occ.size();
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << hi;
} // ~W