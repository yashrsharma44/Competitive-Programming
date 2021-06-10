#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    n = n * 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> ans(n, -1);
    int p = 0;
    for (int i = 0; i < n; i += 2) {
        ans[i] = a[p];
        // cout << p << " " << a[i] << endl;
        p++;
    }

    for (int i = 1; i < n; i += 2) {
        ans[i] = a[p];
        p++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
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