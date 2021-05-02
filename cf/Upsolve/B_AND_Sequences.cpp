#include <bits/stdc++.h>
#define int long long

int MOD = (int)1e9 + 7;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int total = a[0];
    for (int i = 1; i < n; i++) total &= a[i];

    // check how many total named elements are there
    int count = 0;
    for (int el : a) {
        if (el == total) count++;
    }

    if (count == 0) {
        cout << 0 << endl;
        return;
    }

    int ans = 1;
    for (int i = count; i > count - 2; i--) {
        ans *= i;
        ans %= MOD;
    }

    for (int i = 1; i <= n - 2; i++) {
        ans *= i;
        ans %= MOD;
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