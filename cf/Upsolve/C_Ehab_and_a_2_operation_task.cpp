#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> ans;
    // lets make a[i] -> i, i is 0 indexed
    vector<int> pre(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        // lets make a[i] -> n * m + i
        int val = a[i] - i;
        int diff = 0;
        if (val < 0) {
            diff = (n + i) - a[i];
            // diff = val - a[i];
        } else {
            int q = (val + n - 1) / n;
            diff = q * n - val;
        }
        ans.push_back({1, i + 1, diff});
        // need to add diff to all prefix
        for (int j = 0; j <= i; j++) {
            a[j] += diff;
        }
    }

    ans.push_back({2, n, n});
    // now mod to all the elements
    for (int i = 0; i < n; i++) {
        a[i] %= n;
    }

    // cout << "DBG: " << endl;
    // for (auto el : a) cout << el << " ";
    // cout << endl;

    cout << ans.size() << endl;
    for (auto el : ans) {
        for (auto e : el) cout << e << " ";
        cout << endl;
    }
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