#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> segments;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        segments.push_back({u, v});
    }
    // try each a[i] as a possible max and then
    // apply segments which do not modify index i
    int ans = 0;
    vector<int> order;
    for (int i = 0; i < n; i++) {
        // choose all segments which do not affect i
        vector<int> b(a.begin(), a.end());
        vector<int> localOrder;
        for (int j = 0; j < m; j++) {
            if (i + 1 >= segments[j][0] && i + 1 <= segments[j][1]) continue;
            for (int k = segments[j][0]; k <= segments[j][1]; k++) {
                b[k - 1] -= 1;
            }
            localOrder.push_back(j);
        }

        // choose min
        int min_ = INT_MAX, max_ = INT_MIN;
        for (int j = 0; j < n; j++) {
            min_ = min(min_, b[j]);
            max_ = max(max_, b[j]);
        }
        if (abs(max_ - min_) > ans) {
            ans = max(ans, abs(max_ - min_));
            order = localOrder;
        }
    }

    cout << ans << endl;
    cout << order.size() << endl;
    for (auto el : order) cout << el + 1 << " ";
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