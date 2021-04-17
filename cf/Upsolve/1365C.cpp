#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]] = {i};
    }
    for (int i = 0; i < n; i++) {
        mp[b[i]].push_back(i);
    }

    int ans = 0;
    map<int, int> count;
    for (int el : a) {
        auto ids = mp[el];
        int diff = ids[1] - ids[0];
        if (diff < 0) diff += n;
        count[diff] += 1;
        ans = max(ans, count[diff]);
    }

    cout << ans << endl;
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