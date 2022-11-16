#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int k, m, n;
    cin >> k >> m >> n;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> ans;
    int p1 = 0, p2 = 0;
    while (p1 < n && p2 < m) {
        if (a[p1] == 0) {
            ans.push_back(0);
            k++;
            p1++;
        } else if (b[p2] == 0) {
            ans.push_back(0);
            p2++;
            k++;
        } else if (a[p1] <= k) {
            ans.push_back(a[p1]);
            p1++;
        } else if (b[p2] <= k) {
            ans.push_back(b[p2]);
            p2++;
        } else {
            cout << -1 << endl;
            return;
        }
    }

    while (p1 < n) {
        if (a[p1] <= k) {
            if (a[p1] == 0) k++;
            ans.push_back(a[p1]);
        } else {
            cout << -1 << endl;
            return;
        }
        p1++;
    }

    while (p2 < m) {
        if (b[p2] <= k) {
            if (b[p2] == 0) k++;
            ans.push_back(b[p2]);
        } else {
            cout << -1 << endl;
            return;
        }
        p2++;
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
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