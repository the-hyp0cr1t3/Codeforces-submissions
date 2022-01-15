/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 17:38:30
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
    const int N = 1e7 + 5;

    int i, n, a;
    cin >> a >> n;

    queue<int> q; q.push(1);
    vector<int> d(N, -1); d[1] = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if(cur == n)
            return cout << d[cur], 0;

        int64_t nxt = 1LL * cur * a;
        if(nxt < N and d[nxt] == -1) {
            d[nxt] = d[cur] + 1;
            q.push(nxt);
        }

        if(cur % 10 == 0) continue;

        int _ = cur;
        string s;
        while(_) {
            s += _ % 10 + '0';
            _ /= 10;
        }

        rotate(s.begin(), s.begin() + 1, s.end());
        nxt = 0;
        while(!s.empty()) {
            nxt = nxt * 10 + s.back() - '0';
            s.pop_back();
        }

        if(nxt < N and d[nxt] == -1) {
            d[nxt] = d[cur] + 1;
            q.push(nxt);
        }
    }

    cout << -1;
} // ~W