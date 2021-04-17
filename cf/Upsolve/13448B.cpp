#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> dis;
    for (auto el : a) dis.insert(el);
    if (dis.size() > k) {
        cout << -1 << endl;
        return;
    }

    cout << n * k << endl;

    for (int i = 0; i < n; i++) {
        for (auto el : dis) cout << el << " ";
        for (int j = 0; j < k - (int)dis.size(); j++) {
            cout << 1 << " ";
        }
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