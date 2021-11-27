/**
 🍪 the_hyp0cr1t3
 🍪 27.11.2021 17:32:54
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

    int i; string a, b; bool bad = false;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(i = 0; i < min(a.size(), b.size()); i++)
        bad |= a[i] - '0' + b[i] - '0' > 9;

    cout << (bad? "Hard" : "Easy");
} // ~W