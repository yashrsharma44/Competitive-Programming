#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        a.push_back({u, i});
    }

    // sort(a.begin(), a.end());
    int i = 0;
    while (i < n - 1 && k > 0) {
        if (a[i][0] == 0)
            i++;
        else {
            int diff = a[i][0];
            if (diff >= k) {
                a[i][0] -= k;
                a[n - 1][0] += k;
                k = 0;

            } else {
                k -= diff;
                a[n - 1][0] += diff;
                a[i][0] = 0;
            }
        }
    }

    vector<int> ans(n, 1);
    for (auto el : a) {
        ans[el[1]] = el[0];
    }
    for (auto el : ans) cout << el << " ";
    cout << endl;
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