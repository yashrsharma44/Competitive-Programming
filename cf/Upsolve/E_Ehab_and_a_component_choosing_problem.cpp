#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // store the max sum possible including the node
    vector<int> dp(n + 1, 0);
    int maxSum = INT_MIN, k = 0;
    function<void(int, int, int)> dfs1 = [&](int node, int par, int countMax) {
        // always include the node as a component
        dp[node] = a[node];
        for (auto nei : adj[node]) {
            if (nei == par) continue;

            // compute the values of child, and see if you want to include that child
            // if you want to exclude, use 0 instead of sum of child
            dfs1(nei, node, countMax);

            // dp would be populated after the dfs call
            dp[node] += max(dp[nei], 0LL);
        }
        if (countMax == 0)
            maxSum = max(maxSum, dp[node]);
        else if (dp[node] == maxSum) {
            // use this node, so that the parent node cannot use it
            dp[node] = 0;
            k++;
        }
    };

    // find the max sum subtree
    // rooted tree at 1
    dfs1(1, -1, 0);

    // now that we have the maxSum, lets check how many components have
    // sum == maxSum
    dfs1(1, -1, 1);

    cout << k * maxSum << " " << k << endl;
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