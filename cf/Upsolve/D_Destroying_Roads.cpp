#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

    // Multisource Shortest Path using BFS
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));

    auto bfs = [&](int start) {
        // vis.resize(n + 1, false);
        // vector<bool> vis(n + 1, false);

        // vis[start] = true;
        dist[start][start] = 0;

        queue<int> q({start});

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto nei : adj[node]) {
                if (dist[start][nei] == -1) {
                    // vis[nei] = true;
                    dist[start][nei] = 1 + dist[start][node];
                    q.push({nei});
                }
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dist[i][j] << " \n"[j == n];
    //     }
    // }

    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
        cout << -1 << endl;
        return;
    }

    // consider that the paths would clash and pass through node i - node j
    int ans = 0;
    // cout << "Dist: " << endl;
    for (int _ = 0; _ < 2; _++) {
        swap(s1, t1);
        // swap(s2, t2);
        // swap(l1, l2);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // cout << dist[i][j] << " \n"[j == n];
                vector<int> v = {dist[s1][i] + dist[i][j] + dist[j][t1], dist[s2][i] + dist[j][t2] + dist[i][j]};
                int delta = m - (v[0] + v[1] - dist[i][j]);
                if (v[0] <= l1 && v[1] <= l2) {
                    // cout << i << "->" << j << " " << v[0] << " " << v[1] << endl;
                    ans = max(ans, delta);
                }
            }
        }
    }

    if (dist[s1][t1] <= l1 && dist[s2][t2] <= l2) {
        ans = max(ans, m - (dist[s1][t1] + dist[s2][t2]));
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