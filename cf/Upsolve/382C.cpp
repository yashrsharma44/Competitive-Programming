#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    bool isSame = true;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) isSame = false;
    }
    if (isSame) {
        cout << 1 << endl;
        cout << a[0] << endl;
        return;
    }
    if (n == 2) {
        int diff = a[1] - a[0];
        vector<int> ans;
        ans.push_back(a[0] - diff);
        if (abs(diff) % 2 == 0) {
            ans.push_back((a[0] + a[1]) >> 1);
        }
        ans.push_back(a[1] + diff);
        cout << ans.size() << endl;
        for (auto el : ans) {
            cout << el << " ";
        }
        cout << endl;
        return;
    }

    set<int> delta;
    for (int i = 1; i < n; i++) {
        delta.insert(a[i] - a[i - 1]);
    }

    if (delta.size() > 2) {
        cout << 0 << endl;
        return;
    }
    if (delta.size() == 2) {
        int a = *delta.begin();
        int b = *delta.rbegin();
        if (max(a, b) != 2 * min(a, b)) {
            cout << 0 << endl;
            return;
        }
    }
    if (delta.size() == 1) {
        int diff = *delta.begin();
        cout << 2 << endl;
        cout << a[0] - diff << " " << a.back() + diff << endl;
        return;
    }
    int diff = *delta.begin();
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == 2 * diff) {
            cnt += 1;
        }
    }
    if (cnt > 1) {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == 2 * diff) {
            cout << 1 << endl;
            cout << a[i - 1] + diff << endl;
        }
    }
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