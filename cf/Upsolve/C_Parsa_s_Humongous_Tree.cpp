#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];

    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // tree dp
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // dp[i][0] ->max
    // dp[i][1] ->min
    function<void(int, int)> dfs = [&](int node, int par) {
        for (auto nei : adj[node]) {
            if (nei == par) continue;

            // update the childs
            dfs(nei, node);

            // update the dp

            // update the max
            dp[node][0] += max({abs(r[node] - l[nei]) + dp[nei][1], abs(r[node] - r[nei]) + dp[nei][0]});

            // update the min
            dp[node][1] += max({abs(l[node] - l[nei]) + dp[nei][1], abs(l[node] - r[nei]) + dp[nei][0]});
        }

        return;
    };

    dfs(1, -1);

    cout << max(dp[1][0], dp[1][1]) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}