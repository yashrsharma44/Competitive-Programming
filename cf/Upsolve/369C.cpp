#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    int cnt = 0;
    vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);
    vector<bool> color(n + 1, true);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(v);
        adj[v].push_back(u);
        color[u] = color[u] && (w == 2 ? false : true);
        color[v] = color[v] && (w == 2 ? false : true);
    }
    vector<int> dp(n + 1, 0);
    vector<bool>
        vis(n + 1, false);
    function<void(int)> dfs = [&](int node) {
        // cout << "COLOR: " << node << " " << color[node] << endl;
        if (!color[node]) {
            dp[node] += 1;
        }

        for (auto nei : adj[node]) {
            if (!vis[nei]) {
                vis[nei] = true;
                dfs(nei);
                dp[node] += dp[nei];
                // cout << node << "->" << dp[node] << endl;
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        // cout << i << " " << dp[i] << endl;
        if (dp[i] == 1) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (auto el : ans) cout << el << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
}