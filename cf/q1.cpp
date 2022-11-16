#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int node, vector<int> &comp, vector<int> *adj, vector<bool> &vis) {
    for (auto nei : adj[node]) {
        if (vis[nei]) continue;
        vis[nei] = true;
        comp.push_back(nei);
        dfs(nei, comp, adj, vis);
    }
};

int solve(int graph_nodes, vector<int> graph_from, vector<int> graph_to) {
    vector<int> adj[graph_nodes + 1];

    for (int i = 0; i < graph_from.size(); i++) {
        adj[graph_from[i]].push_back(graph_to[i]);
        adj[graph_to[i]].push_back(graph_from[i]);
    }
    vector<bool> vis(graph_nodes + 1, false);
    int answer = 0;
    for (int el = 1; el <= graph_nodes; el++) {
        if (!vis[el]) {
            vis[el] = true;
            vector<int> comp({el});
            dfs(el, comp, adj, vis);

            // compute size
            int val = comp.size();
            answer += ceil(sqrt(val));
        }
    }

    return answer;
}

int32_t main() {
    auto ans = solve(10, {1, 1, 2, 3, 7}, {2, 3, 4, 5, 8});
    cout << ans << endl;
}