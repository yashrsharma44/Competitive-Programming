#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    vector<vector<int>> dis(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    vector<int> a(n), vis(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (auto &el : a) --el;
    reverse(a.begin(), a.end());
    vector<int> ans;
    for (auto k : a) {
        vis[k] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = min({adj[i][j], adj[i][k] + adj[k][j]});
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i] && vis[j])
                    sum += adj[i][j];
            }
        }
        ans.push_back(sum);
    }
    for (auto it = ans.rbegin(); it != ans.rend(); it++) cout << *it << " ";
    cout << endl;
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