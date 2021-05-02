#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, max_ = 0, maxel = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] > max_) {
            max_ = mp[a[i]];
            maxel = i;
        }
    }

    vector<vector<int>> ans;
    for (int i = maxel; i < n - 1; i++) {
        if (abs(a[i + 1] - a[i]) != 0) {
            int op = a[i + 1] < a[i] ? 1 : 2;
            ans.push_back({op, i + 1, i});
            a[i + 1] = a[i];
        }
    }
    for (int i = maxel; i > 0; i--) {
        if (abs(a[i] - a[i - 1]) != 0) {
            int op = a[i - 1] < a[i] ? 1 : 2;
            ans.push_back({op, i - 1, i});
            a[i - 1] = a[i];
        }
    }
    cout << ans.size() << endl;
    for (auto el : ans) {
        cout << el[0] << " " << el[1] + 1 << " " << el[2] + 1 << endl;
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