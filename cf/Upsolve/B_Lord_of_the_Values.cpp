#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto print = [&](int i, int j) {
        cout << 1 << " " << i << " " << j << endl;
        cout << 2 << " " << i << " " << j << endl;

        cout << 1 << " " << i << " " << j << endl;
        cout << 1 << " " << i << " " << j << endl;

        cout << 2 << " " << i << " " << j << endl;
        cout << 1 << " " << i << " " << j << endl;
    };

    cout << (3 * n) << endl;
    for (int i = 0; i < n / 2; i++) {
        int j = i + n / 2;
        print(i + 1, j + 1);
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