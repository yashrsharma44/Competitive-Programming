#include <bits/stdc++.h>
#define int unsigned long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    int c = (x + n - 1LL) / n;
    int r = (x + n - 1LL) % n;
    // cout << c << " " << r << endl;
    unsigned long long ans = m * (r) + (c);
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