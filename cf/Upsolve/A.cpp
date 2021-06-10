#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (((1 << i) & n) != 0) {
            ans = i;
            // cout << i << endl;
            break;
        }
    }

    // cout << ((1 << 4) & n) << endl;

    cout << (1 << ans) - 1 << endl;
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