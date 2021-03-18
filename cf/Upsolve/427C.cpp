#include <bits/stdc++.h>
#define int long long
// #define MOD 100000000
using namespace std;

void dfs(vector<int> *adj, vector<bool> &vis, int node, vector<int> &topo) {
    for (auto nei : adj[node]) {
        if (!vis[nei]) {
            vis[nei] = true;
            dfs(adj, vis, nei, topo);
        }
    }
    topo.push_back(node);
}

void dfs2(vector<int> *adj, vector<bool> &vis, int node, vector<int> &comp) {
    comp.push_back(node);
    for (auto nei : adj[node]) {
        if (!vis[nei]) {
            vis[nei] = true;
            dfs2(adj, vis, nei, comp);
        }
    }
}

void solve() {
    // Have to create a Strongly Connected Components graph
    // Connected Components holds for Undirected Graphs
    // Strongly Connected Components for Directed Graphs

    // Two Algorithms:
    // 1. Kosaraju Algorithm
    // 2. Tarjan's Algorithm

    // Let's use Kosaraju's algorithm, much simpler
    int MOD = 1e9 + 7;
    int ans = 1;
    int cost = 0;

    int n;
    cin >> n;
    vector<int> adj[n];
    vector<int> adjT[n];

    vector<int> pw(n);
    for (int i = 0; i < n; i++) cin >> pw[i];

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    vector<bool> vis(n, false);
    // Get the topo ordering
    vector<int> topo;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(adj, vis, i, topo);
        }
    }
    reverse(topo.begin(), topo.end());

    // Process elements in topo ordering using the adjT
    for (int i = 0; i < n; i++) vis[i] = false;
    for (int i = 0; i < n; i++) {
        int el = topo[i];
        if (!vis[el]) {
            vector<int> comp;
            vis[el] = true;
            dfs2(adjT, vis, el, comp);

            // get min cost
            int min_ = INT_MAX;
            for (auto el : comp) {
                min_ = min(min_, pw[el]);
            }
            // count the min occur
            int count = 0;
            for (auto el : comp) {
                if (pw[el] == min_) {
                    count += 1;
                }
            }
            cost += min_;
            ans *= count;
            ans %= MOD;
        }
    }

    cout << cost << " " << ans << endl;
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