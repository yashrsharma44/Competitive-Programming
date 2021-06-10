#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 1;
    int run_max = a[0];
    int run_delta = INT_MAX;
    for (int i = 1; i < n; i++) {
        int delta = abs(a[i] - a[i - 1]);
        run_delta = min(run_delta, delta);

        run_max = max(run_max, a[i]);

        if (run_delta >= run_max) {
            ans++;
        } else {
            break;
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