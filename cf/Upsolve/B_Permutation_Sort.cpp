#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool isSort = true;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] != i) {
            isSort = false;
            break;
        }
    }

    if (isSort) {
        cout << 0 << endl;
        return;
    }

    int min_ = 0, max_ = 0;
    for (int i = 0; i < n; i++) {
        if (a[min_] > a[i]) {
            min_ = i;
        }
        if (a[max_] < a[i]) {
            max_ = i;
        }
    }

    if (min_ == 0 || max_ == n - 1) {
        cout << 1 << endl;
        return;
    }

    if (min_ == n - 1 && max_ == 0) {
        cout << 3 << endl;
        return;
    }

    cout << 2 << endl;
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