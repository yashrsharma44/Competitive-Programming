#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    queue<int> q;
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            q.push(i);
            vis[i] = true;
        }
    }

    while (!q.empty() && m > 0) {
        int sz = q.size();
        vector<int> chosen;
        while (sz--) {
            auto node = q.front();
            q.pop();

            if (node - 2 >= 0 && s[node - 1] == '0' && s[node - 2] == '0') {
                chosen.push_back(node - 1);
                if (!vis[node - 1]) {
                    vis[node - 1] = true;
                    q.push(node - 1);
                }
            } else if (node - 1 == 0 && s[node - 1] == '0') {
                s[node - 1] = '1';
                chosen.push_back(node - 1);
            }

            if (node + 2 < n && s[node + 1] == '0' && s[node + 2] == '0') {
                chosen.push_back(node + 1);
                if (!vis[node + 1]) {
                    vis[node + 1] = true;
                    q.push(node + 1);
                }
            } else if (node + 1 == n - 1 && s[node + 1] == '0') {
                chosen.push_back(node + 1);
            }
        }

        for (auto id : chosen) s[id] = '1';

        m--;
    }

    cout << s << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}