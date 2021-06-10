#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    vector<int> a({1, 5, 3, 2, 6, 4});
    // vector<int> a({3, 1, 2, 4});
    int n = a.size();
    auto f1 = [&](int i, int j, int x) {
        return max(min(x, a[i]), min(x + 1, a[j]));
    };

    auto f2 = [&](int i, int j, int x) {
        return min(max(x, a[i]), max(x + 1, a[j]));
    };

    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;
        // for (int j = i + 1; j < n; j++) {
        for (int x = 1; x < n; x++) {
            cout << "[" << a[i] << " " << a[j] << " " << x << "]: "
                 << "max: " << f1(i, j, x) << " min: " << f2(i, j, x) << endl;
        }
        cout << endl;
        // }
    }
    for (int x = 1; x < n; x++) {
        int i = n - 1, j = n - 2;
        cout << "[" << a[i] << " " << a[j] << " " << x << "]: "
             << "max: " << f1(i, j, x) << " min: " << f2(i, j, x) << endl;
    }
    cout << endl;
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