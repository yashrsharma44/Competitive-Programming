#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k * 2 > (n * n) + 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n && k > 0; i++) {
        int j = (i % 2 == 0) ? 0 : 1;
        for (; j < n && k > 0; j += 2) {
            a[i][j] = 1;
            k--;
        }
    }

    for (auto el : a) {
        for (auto e : el) {
            if (e == 0)
                cout << "S";
            else
                cout << "L";
        }
        cout << endl;
    }
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