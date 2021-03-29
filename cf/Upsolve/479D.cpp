#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto check = [&](int val1, int val2) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (a[m] == val1)
                return true;
            else if (a[m] < val1) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        l = 0;
        r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (a[m] == val2)
                return true;
            else if (a[m] < val2) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return false;
    };

    // check for a pos a[i] + x or a[i] - x exists, if yes, x is covered
    // similar for y
    bool isX = false,
         isY = false;
    for (int i = 0; i < n; i++) {
        if (check(a[i] + x, a[i] - x)) {
            isX = true;
        }

        if (check(a[i] + y, a[i] - y)) {
            isY = true;
        }
    }

    if (isX && isY) {
        cout << 0 << endl;
        return;
    }

    if ((isX && !isY) || (isY && !isX)) {
        cout << 1 << endl;
        if (isX) {
            cout << a[0] + y << endl;
        }
        if (isY) {
            cout << a[0] + x << endl;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        int val1 = a[i] + x, val2 = a[i] - x;
        int val3 = a[i] + y, val4 = a[i] - y;

        // check if val1 + y or val1 - y exists
        if (val1 <= a.back() && check(val1 + y, val1 - y)) {
            cout << 1 << endl;
            cout << val1 << endl;
            return;
        }

        // check if val2 + y or val2 - y exists
        if (val2 >= a[0] && check(val2 + y, val2 - y)) {
            cout << 1 << endl;
            cout << val2 << endl;
            return;
        }

        // check if val3 + x or val3 - x exists
        if (val3 <= a.back() && check(val3 + x, val3 - x)) {
            cout << 1 << endl;
            cout << val3 << endl;
            return;
        }

        // check if val4 + x or val4 - x exists
        if (val4 >= a[0] && check(val4 + x, val4 - x)) {
            cout << 1 << endl;
            cout << val4 << endl;
            return;
        }
    }

    cout << 2 << endl;
    cout << a[0] + x << " " << a[0] + y << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
}