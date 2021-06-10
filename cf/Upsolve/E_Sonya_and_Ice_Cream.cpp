
#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edges;
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        deg[u]++;
        deg[v]++;
    }

    vector<vector<int>> adj[n + 1];
    for (auto ed : edges) {
        adj[ed[0]].push_back({ed[1], ed[2]});
        adj[ed[1]].push_back({ed[0], ed[2]});
    }
    int DBG = -1;

    auto bfs = [&](int &mark, int count, int &t) {
        // push leaves into queue
        vector<bool> marked(n + 1, false);
        vector<int> maxDis(1e5 + 5, 0);
        queue<vector<int>> q;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) q.push({i, -1});
        }

        vector<int> cdeg = deg;
        vector<bool> vis(n + 1, false);

        while (!q.empty()) {
            auto entry = q.front();
            q.pop();
            int node = entry[0], par = entry[1];
            int dis = maxDis[node];

            for (auto nei : adj[node]) {
                if (vis[nei[0]]) continue;
                maxDis[nei[0]] = max(maxDis[nei[0]], maxDis[node] + nei[1]);

                if (nei[1] + maxDis[node] <= count) {
                    // mark the node as marked
                    marked[node] = true;
                    vis[node] = true;
                }
                cdeg[nei[0]]--;
                if (cdeg[nei[0]] == 1) {
                    q.push({nei[0], node});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (marked[i]) mark++;
        }
    };

    // choose a node which has the max deg for dfs
    int startNode = 1;
    for (int i = 1; i <= n; i++) {
        if (deg[startNode] < deg[i]) startNode = i;
    }
    // cout << "Start Node" << startNode << endl;
    auto check = [&](int m) {
        int mark = 0;
        int t = 0;
        bfs(mark, m, t);

        return n - mark <= k;
    };

    // binary search
    // first True

    // for (int i = 0; i <= 15; i++) {
    //     cout << i << " " << check(i) << endl;
    // }

    int l = 0, r = 1e4 * n;
    while (l < r) {
        int m = (l + r) >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }

    cout << l << endl;
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