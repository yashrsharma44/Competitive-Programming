#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // lets expand around from the center :)
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i] * b[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int local = sum;
        for (int l = i - 1, r = i + 1; l >= 0 && r < n; l--, r++) {
            local += b[l] * (a[r] - a[l]) + b[r] * (a[l] - a[r]);
            ans = max(ans, local);
        }
        ans = max(ans, local);

        local = sum;
        for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++) {
            local += b[l] * (a[r] - a[l]) + b[r] * (a[l] - a[r]);
            ans = max(ans, local);
        }
        ans = max(ans, local);

        local = sum;
        for (int l = i - 1, r = i; l >= 0 && r < n; l--, r++) {
            local += b[l] * (a[r] - a[l]) + b[r] * (a[l] - a[r]);
            ans = max(ans, local);
        }
        ans = max(ans, local);
    }

    cout << ans << endl;
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