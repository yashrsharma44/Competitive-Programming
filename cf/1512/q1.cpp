#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (auto el : a) mp[el]++;
    int key = -1;
    for (auto el : mp) {
        if (el.second == 1) key = el.first;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            cout << i + 1 << endl;
            return;
        }
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
