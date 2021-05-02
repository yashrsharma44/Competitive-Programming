#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        mp[u]++;
    }
    for (int i = 0; i < m; i++) {
        int u;
        cin >> u;
        mp[u]++;
    }
    int ans = 0;
    for (auto el : mp) {
        if (el.second > 1) {
            ans += el.second - 1;
        }
    }

    cout << ans << endl;
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