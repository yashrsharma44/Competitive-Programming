#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(a.begin(), a.end());

    sort(b.begin(), b.end());
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        pos.push_back(i);
    }

    if (pos.size() <= 2) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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