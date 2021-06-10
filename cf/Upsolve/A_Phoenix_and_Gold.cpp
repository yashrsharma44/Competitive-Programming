#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int pre = 0;
    for (int i = 0; i < n; i++) {
        pre += a[i];
        if (pre == x) {
            // swap with right if possible
            // else not possible
            if (i < n - 1)
                swap(a[i], a[i + 1]);
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    for (auto el : a) cout << el << " ";
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