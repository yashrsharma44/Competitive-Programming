#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int q;
    cin >> q;
    vector<vector<int>> qq;
    for (int i = 0; i < q; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        qq.push_back({u, v, l});
    }

    // floyd warshall
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (auto nei : adj[i]) {
            d[i][nei[0]] = nei[1];
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((d[i][j] > d[i][k] + d[k][j]) && d[i][k] != INT_MAX && d[k][j] != INT_MAX) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    int ans = 0;
    for (auto ed : qq) {
        if (d[ed[0]][ed[1]] <= ed[2]) ans++;
    }

    cout << ans << endl;
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