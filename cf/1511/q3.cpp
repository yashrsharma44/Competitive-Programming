#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> t(q);
    for (int i = 0; i < q; i++) cin >> t[i];

    map<int, int> first;
    for (int i = 0; i < n; i++) {
        if (first.count(a[i]) == 0) {
            first[a[i]] = i + 1;
        }
    }

    for (auto qq : t) {
        cout << first[qq] << " ";
        for (auto &el : first) {
            if (el.second < first[qq]) el.second++;
        }
        first[qq] = 1;
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
}
