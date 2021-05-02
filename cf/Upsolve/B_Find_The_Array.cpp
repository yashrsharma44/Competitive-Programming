#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) cin >> a[i];

    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            s1 += a[i];
        else
            s2 += a[i];
    }

    if (s1 > s2) {
        for (int i = 0; i < n; i++) {
            // block even pos
            if (i % 2 == 0)
                b.push_back(a[i]);
            else
                b.push_back(1);
        }
    } else {
        for (int i = 0; i < n; i++) {
            // block odd pos
            if (i % 2 == 1) {
                b.push_back(a[i]);
            } else {
                b.push_back(1);
            }
        }
    }

    for (auto el : b) {
        cout << el << " ";
    }
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