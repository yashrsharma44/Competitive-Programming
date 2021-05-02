#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<vector<int>> edges(m, vector<int>(2, -1));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> vis(n + 1, 0);
    // we need to check if the graph is bipartite or not
    auto check = [&]() {
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    for (auto nei : adj[node]) {
                        if (vis[nei] == 0) {
                            vis[nei] = vis[node] == 1 ? 2 : 1;
                            q.push(nei);
                        } else if (vis[nei] == vis[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    };

    if (!check()) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    string ans = "";
    for (auto edge : edges) {
        if (vis[edge[0]] == 1 && vis[edge[1]] == 2)
            ans += "1";
        else
            ans += "0";
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