#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto check = [&](int val) {
        vector<int> less;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] < val) less.push_back(i);
            mn = min(mn, a[i]);
        }

        if (mn >= val) return true;

        int cnt = 0;
        int p1 = 0;
        map<int, int> mp;
        while (p1 < less.size()) {
            int p2 = p1;
            int min_ = a[less[p1]];
            while (p2 < less.size() && less[p2] - less[p1] + 1 <= w) {
                min_ = min(min_, a[less[p2]]);
                p2++;
            }
            // cout << "MIN_" << min_ << " P2: " << p2 << endl;
            mp[min_] += 1;
            cnt += 1;
            p1 = p2;
        }
        // cout << "DBG: " << val << endl;
        // cout << "LESS: ";
        // for (auto el : less) cout << el << " ";
        // cout << endl;
        // for (auto el : mp) {
        //     cout << el.first << " " << el.second << endl;
        // }

        int count = 0;
        for (auto el : mp) {
            if (el.first >= val) {
                break;
            }
            count += el.second;
        }
        return count <= m;
    };

    for (int i = 1; i <= 10; i++) {
        cout << i << " " << check(i) << endl;
    }

    // int l = 0, r = 1000000001;
    // // find the last True
    // // lets use the bs: r-l>1
    // while (r - l > 1) {
    //     int m = (l + r) >> 1;
    //     if (check(m)) {
    //         l = m;
    //     } else {
    //         r = m;
    //     }
    // }
    // cout << l << endl;
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