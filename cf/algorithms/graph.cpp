#include <bits/stdc++.h>
using namespace std;

class DSU {
   public:
    int N;
    vector<int> par, rnk;

    DSU(int n) {
        this->N = n;
        this->par = vector<int>(this->N + 1, -1);

        // self node is par to start with
        // all disjoint nodes
        for (int i = 0; i <= n; i++) this->par[i] = i;

        this->rnk = vector<int>(this->N + 1, 1);
    }

    bool Union(int x, int y) {
        int xr = this->find(x), yr = this->find(y);
        if (xr == yr) return false;

        if (this->rnk[xr] < this->rnk[yr]) {
            swap(xr, yr);
        }

        this->rnk[xr] += this->rnk[yr];
        this->par[yr] = xr;
        return true;
    }

    int find(int x) {
        if (this->par[x] != x) this->par[x] = this->find(this->par[x]);
        return this->par[x];
    }
};

int main() {
    // int n = 10;
    int n = 4;
    // vector<vector<int>> edges({
    //     {1, 2, 2}, {3, 4, 8}, {5, 6, 12}, {7, 8, 1}, {9, 10, 8}, {1, 3, 4}, {1, 4, 3},
    //     //  {3, 7, 10}, {5, 8, 8}, {9, 6, 1}
    // });

    vector<vector<int>> edges({{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}});

    vector<vector<int>> adj[n + 1];
    vector<int> adj2[n + 1];
    for (auto el : edges) {
        // adj[el[0]].push_back({el[1], el[2]});
        adj2[el[0]].push_back(el[1]);
        // adj[el[1]].push_back({el[0], el[2]});
    }

    // TC: O(V+E)
    // SC: O(V+E)
    auto bfs = [&]() {
        vector<bool> vis(n + 1, false);

        for (int i = 1; i <= 10; i++) {
            if (!vis[i]) {
                vis[i] = true;
                queue<int> q;

                q.push(i);
                while (!q.empty()) {
                    auto node = q.front();
                    cout << node << " ";
                    q.pop();

                    for (auto nei : adj[node]) {
                        if (!vis[nei[0]]) {
                            vis[nei[0]] = true;
                            q.push(nei[0]);
                        }
                    }
                }
            }

            cout << endl;
        }
    };

    // TC: O(V+E)
    // SC: O(V+E)
    auto dfs = [&]() {
        vector<bool> vis(n + 1, false);

        function<void(int)> dfs_helper = [&](int node) {
            cout << node << " ";

            for (auto nei : adj[node]) {
                if (vis[nei[0]]) continue;

                vis[nei[0]] = true;
                dfs_helper(nei[0]);
            }
        };

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                dfs_helper(i);
                cout << endl;
            }
        }
    };

    // TC: O(MlogM + O(1))
    // DSU has a time complexity of O(alpha(n)), where alpha(n) <= 4 for all practical purpose
    //
    auto kruskal_mst = [&]() {
        DSU *dsu = new DSU(10);

        sort(edges.begin(), edges.end(), [&](vector<int> p1, vector<int> p2) {
            return p1[2] < p2[2];
        });

        int ans = 0;
        for (auto el : edges) {
            if (dsu->Union(el[0], el[1])) {
                cout << el[0] << " " << el[1] << " ->" << el[2] << endl;
                ans += el[2];
            }
        }
        cout << ans << endl;
    };

    // TC: O((N+M)logN )
    auto prim_mst = [&]() {
        multiset<vector<int>> pq;
        pq.insert({0, 1});

        vector<bool> vis(n + 1, false);
        int ans = 0;
        while (!pq.empty()) {
            auto node = *(pq.begin());
            pq.erase(pq.find(node));

            if (vis[node[1]]) continue;
            vis[node[1]] = true;

            ans += node[0];

            for (auto nei : adj[node[1]]) {
                if (vis[nei[0]]) continue;
                pq.insert({nei[1], nei[0]});
            }
        }

        cout << ans << endl;
    };

    auto dijkstras = [&](int start) {
        map<int, int> dist;
        dist[start] = 0;

        multiset<vector<int>> pq;
        pq.insert({0, start});

        while (!pq.empty()) {
            auto node = *(pq.begin());
            pq.erase(pq.find(node));

            for (auto nei : adj[node[1]]) {
                if (dist.count(nei[0]) == 0 || dist[node[1]] + nei[1] < dist[nei[0]]) {
                    dist[nei[0]] = dist[node[1]] + nei[1];
                    pq.insert({nei[1], nei[0]});
                }
            }
        }

        cout << "Distance\n";
        for (auto el : dist) {
            cout << el.first << " " << el.second << endl;
        }
    };

    auto floyd_warshall = [&]() {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i <= n; i++) {
            dist[i][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (auto nei : adj[i]) {
                dist[nei[0]][i] = nei[1];
                dist[i][nei[0]] = nei[1];
            }
        }

        for (int k = 0; k <= n; k++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << i << " " << j << " ->" << dist[i][j] << endl;
            }
            cout << endl;
        }
    };

    auto bridges = [&]() {
        vector<vector<int>> ans;
        vector<int> tin(n + 1, -1), low(n + 1, -1);
        int timer = 0;

        vector<bool> vis(n + 1, false);
        function<void(int, int)> art = [&](int node, int par) {
            low[node] = tin[node] = ++timer;

            for (auto nei : adj[node]) {
                if (nei[0] == par) continue;

                if (vis[nei[0]]) {
                    low[node] = min(low[node], tin[nei[0]]);
                } else {
                    vis[nei[0]] = true;
                    art(nei[0], node);

                    low[node] = min(low[node], low[nei[0]]);
                    if (low[nei[0]] > tin[node]) {
                        cout << node << " " << nei[0] << endl;
                    }
                }
            }
        };

        for (int i = 0; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                art(i, -1);
            }
        }
    };

    auto articulation_point = [&]() {
        int timer = 0;
        vector<int> low(n + 1, -1), tin(n + 1, -1);

        vector<bool> vis(n + 1, false);
        function<void(int, int)> art = [&](int node, int par) {
            low[node] = tin[node] = ++timer;

            int child = 0;
            for (auto nei : adj[node]) {
                if (nei[0] == par) continue;

                if (vis[nei[0]]) {
                    // back-edge
                    low[node] = min(low[node], tin[nei[0]]);
                } else {
                    vis[nei[0]] = true;
                    child++;
                    art(nei[0], node);

                    low[node] = min(low[node], low[nei[0]]);
                    if (low[nei[0]] >= tin[node] && par != -1) {
                        cout << node << " ";
                    }
                }
            }

            if (par == -1 && child > 1) {
                cout << node << " ";
            }
        };

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                art(i, -1);
            }
        }
        cout << endl;
    };

    // Bi Connected Components
    // Find if the graph contains an articulation point. If no, we have a biconnected graph
    // For bi-connected graphs, we need to push elements to the stack(edges), and pop them if you find an articulation point

    // Strongly Connected Components
    // Do a reverse Topo Ordering of the vertices
    // reverse the graph
    // print the components for a given component
    auto scc = [&]() {
        // topo ordering

        stack<int> topo;
        vector<bool> vis2(n + 1, false);

        function<void(int, int)> scc_dfs = [&](int node, int par) {
            for (auto nei : adj2[node]) {
                if (vis2[nei]) continue;
                vis2[nei] = true;
                scc_dfs(nei, node);
            }
            topo.push(node);
        };

        for (int i = 1; i <= n; i++) {
            if (!vis2[i]) {
                vis2[i] = true;
                scc_dfs(i, -1);
            }
        }

        // reverse the graph
        vector<int> adj3[n + 1];
        for (int i = 0; i <= n; i++) {
            for (auto nei : adj2[i]) {
                adj3[nei].push_back(i);
            }
        }

        // do a traversal with the reverse topo ordering and print the components
        vector<bool> vis(n + 1, false);
        function<void(int, int, vector<int> &)> comp = [&](int node, int par, vector<int> &comps) {
            comps.push_back(node);

            for (auto nei : adj3[node]) {
                if (vis[nei]) continue;
                vis[nei] = true;

                comp(nei, node, comps);
            }
        };

        while (topo.size() > 0) {
            auto node = topo.top();
            topo.pop();
            if (!vis[node]) {
                vis[node] = true;
                vector<int> comps;
                comp(node, -1, comps);

                for (auto el : comps) {
                    cout << el << " ";
                }
                cout << endl;
            }
        }
    };

    // bfs();
    // dfs();
    // kruskal_mst();
    // prim_mst();
    // dijkstras(1);
    // floyd_warshall();
    // bridges();
    // articulation_point();

    scc();
}