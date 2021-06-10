#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        map<vector<int>, int> cache;
        auto getSum = [&](int r) {
            if (cache.count({1, r}) > 0) return cache[{1, r}];

            cout << "? " << 1 << " " << r << endl;
            fflush(stdout);
            int val;
            cin >> val;
            return cache[{1, r}] = val;
        };

        auto print = [&](int val) {
            cout << "! " << val << endl;
            fflush(stdout);
        };

        int l = 0, r = n + 1;
        // Lets cache the request between [l, r) and update the sum
        // between [pos, r)

        // find first el such that pos - sum >= k
        // first True

        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (m - getSum(m) >= k) {
                cache[{1, m}]++;
                r = m;
            } else
                l = m;
        }
        int pos = r;
        print(pos);

        // cout << "DBG: " << endl;
        // for (auto el : cache) {
        //     cout << el.first[0] << " " << el.first[1] << " " << el.second << endl;
        // }

        // Update the cache such that val between (0, n+1) is updated
        // l = 0;
        // r = n + 1;

        // while (r - l > 1) {
        //     int m = (l + r) >> 1;
        //     if (m - getSum(m) >= k) {
        //         r = m;
        //     } else
        //         l = m;
        // }
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