#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mx = 0, mn = 0;
    for (int i = 0; i < n; i++) {
        if (a[mx] < a[i]) {
            mx = i;
        }
        if (a[mn] > a[i]) {
            mn = i;
        }
    }

    int c1 = n - max(mx, mn) + min(mx, mn) + 1;
    int c2 = 1 + max(mx, mn);
    int c3 = n - min(mn, mx);

    cout << min({c1, c2, c3}) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}