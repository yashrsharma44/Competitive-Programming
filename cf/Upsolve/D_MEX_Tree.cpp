#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sum(n, 1);
    vector<int> par(n, -1);
    vector<bool> vis(n, false);
    vis[0] = true;

    function<int(int, int)> dfs = [&](int node, int p) {
        par[node] = p;

        for (auto nei : adj[node]) {
            if (nei == p) continue;
            sum[node] += dfs(nei, node);
        }
        return sum[node];
    };

    // lets populate the subtree sum
    dfs(0, 0);

    vector<int> ans(n + 2, 0);
    ans[0] = ans[1] = n * (n - 1) / 2;

    for (auto nei : adj[0]) {
        ans[1] -= (sum[nei] * (sum[nei] - 1)) / 2;
    }

    int par1 = 1, u = 0, v = 0;
    while (par[par1]) {
        par1 = par[par1];
    }

    auto add = [&](int u, int v) {
        if (v == 0) return sum[u] * (n - sum[par1]);
        return sum[u] * sum[v];
    };

    for (int i = 1; i < n; i++) {
        if (vis[i]) {
            ans[i + 1] = ans[i];
            continue;
        }

        // going up and making sure we dont reach any visited node
        int j = i;
        while (j != u && j != v) {
            if (vis[j]) break;
            vis[j] = true;
            j = par[j];
        }

        if (u == j) {
            u = i;
            ans[i + 1] = add(u, v);
            continue;
        }

        if (v == j) {
            v = i;
            ans[i + 1] = add(v, u);
            continue;
        }

        break;
    }

    for (int i = 1; i <= n + 1; i++)
        cout << ans[i - 1] - ans[i] << " ";
    cout << endl;
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