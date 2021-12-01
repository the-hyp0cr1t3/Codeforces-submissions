/**
 🍪 the_hyp0cr1t3
 🍪 01.12.2021 18:03:42
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace R = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int N = 2e5;
    const int SQRT = 450;

    int i, n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    for(i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    vector<vector<int>> block;
    block.reserve(SQRT);
    for(i = 0; i < SQRT; i++)
        block.emplace_back(max(1, i));

    vector<int> cur(n), day(m);
    vector<int64_t> other(m, m);
    for(i = 0; i < m; i++) {
        int op, k; cin >> op >> k;
        day[i] = --k;
        if(op == 2) {
            other[cur[k]] = i;
            other[i] = cur[k];
        }
        cur[k] = i;
    }

    auto upd_ranges = [&](int len, int x, int st, int delta) {
        st %= len;
        for(int z = (st + x) % len; z != st; z = (z + 1) % len)
            block[len][z] += delta;
    };

    vector<int> ans(m + 1);
    for(i = 0; i < m; i++) {
        int k = day[i];
        if(other[i] > i) {  // create train
            if(x[k] + y[k] < SQRT) {
                // small x + y --> store a block for every x + y value
                upd_ranges(x[k] + y[k], x[k], i, 1);
            } else {
                // large x + y --> n / (x + y) <= SQRT
                for(int64_t j = i; j < other[i]; j += x[k] + y[k]) {
                    ans[min(other[i], j + x[k])]++;
                    ans[min(other[i], j + x[k] + y[k])]--;
                }
            }
        } else {
            if(x[k] + y[k] < SQRT)
                upd_ranges(x[k] + y[k], x[k], other[i], -1);
        }

        ans[i + 1] += ans[i];
        for(int j = 1; j < SQRT; j++)
            ans[i] += block[j][i % j];

        cout << ans[i] << '\n';
    }

} // ~W