#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> h(m), d(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> d[i] >> h[i];
    }
    int max_ = max(h[0] + d[0] - 1, (n - d[m - 1]) + h[m - 1]);
    for (int i = 1; i < m; i++) {
        if (d[i] - d[i - 1] < abs(h[i] - h[i - 1])) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        max_ = max(max_, (h[i] + h[i - 1] + d[i] - d[i - 1]) / 2);
    }

    cout << max_ << endl;
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