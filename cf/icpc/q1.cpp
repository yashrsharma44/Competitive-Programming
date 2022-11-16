#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;
#define MAX 1e7 + 1

int spf[(int)(MAX)];

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAX; i++) spf[i] = i;

    for (int i = 4; i < MAX; i += 2) {
        spf[i] = 2;
    }

    for (int i = 3; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> factorization(int el) {
    set<int> ans;
    while (el > 1) {
        ans.insert(spf[el]);
        el /= spf[el];
    }
    return vector<int>(ans.begin(), ans.end());
}

void solve() {
    int n, k, h;
    cin >> n >> k >> h;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    vector<int> adj[n + 1];
    set<int> nodes;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        nodes.insert(u);
        nodes.insert(v);
    }

    auto dijk = [&](int node) {
        vector<int> dist(n + 1, LLONG_MAX);
        dist[node] = 0;
        multiset<vector<int>> pq;

        pq.insert({0, node});
        while (pq.size() > 0) {
            auto entry = *pq.begin();
            pq.erase(pq.find(entry));

            int d = entry[0], nd = entry[1];
            if (dist[nd] < d) {
                continue;
            }

            for (auto nei : adj[nd]) {
                if (d + 1 < dist[nei]) {
                    dist[nei] = d + 1;
                    pq.insert({d + 1, nei});
                }
            }
        }

        return dist;
    };

    function<int(int, int, int, int)> dfs = [&](int node, int dist, int par, int left) {
        if (left <= 0) return 0LL;
        // 2 choices, we can consider this in our sum
        int ans = 0;
        if (dist >= h) {
            for (auto nei : adj[node]) {
                if (nei == par) continue;
                ans = max(ans, A[node] + dfs(nei, 0, node, left - 1));
            }
        }

        // or we dont consider
        for (auto nei : adj[node]) {
            if (nei == par) continue;
            ans = max(ans, dfs(nei, dist + 1, node, left));
        }

        return ans;
    };

    int maxAns = 0;

    // dp for each node and see how much max we can find
    // rooted at node
    for (auto node : nodes) {
        cout << node << " " << dfs(node, 0, -1, k) << endl;
        maxAns = max(maxAns, dfs(node, 0, -1, k));
    }

    cout << maxAns << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}