#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    // dfs
    // calculate the incre and decre and the total curr value
    function<vector<int>(int, int)> dfs = [&](int node, int par) {
        if (adj[node].size() == 1 && adj[node][0] == par) {
            if (v[node] > 0) {
                return vector<int>({0, abs(v[node])});
            } else {
                return vector<int>({abs(v[node]), 0});
            }
        }

        vector<int> ans = {0, 0};
        for (auto nei : adj[node]) {
            if (nei == par) continue;
            auto res = dfs(nei, node);
            ans[0] = max(ans[0], res[0]);
            ans[1] = max(ans[1], res[1]);
        }
        // cout << node << " MAX: " << ans[0] << " " << ans[1] << endl;
        int cur_val = v[node] + ans[0] - ans[1];
        if (cur_val < 0) {
            ans[0] += abs(cur_val);
        } else {
            ans[1] += abs(cur_val);
        }
        // cout << node << " " << ans[0] << " " << ans[1] << endl;
        return ans;
    };

    auto ans = dfs(1, -1);
    int count = abs(ans[0]) + abs(ans[1]);
    cout << count << endl;
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