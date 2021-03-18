#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    queue<int> q;
    vector<vector<int>> inp(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        cin >> inp[i][0] >> inp[i][1];

        // Enqueue all the nodes with degree 1
        if (inp[i][0] == 1) q.push(i);
    }

    vector<vector<int>> edges;

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (inp[node][0] == 0) continue;
        int adjnode = inp[node][1];

        edges.push_back({node, adjnode});

        inp[adjnode][1] ^= node;
        inp[adjnode][0] -= 1;

        if (inp[adjnode][0] == 1) q.push(adjnode);
    }

    cout << edges.size() << endl;
    for (auto ed : edges) {
        cout << ed[0] << " " << ed[1] << endl;
    }
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