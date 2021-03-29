#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

int bs(vector<int> &pre, vector<int> &a, int k, int i) {
    int n = pre.size();

    // i is 1 indexed
    // find the greatest m such that a[i-1] * (m - i) - pre[m] - pre[i-1] <= k

    for (int j = i - 1; j <= n; j++) {
        cout << j << " " << ((a[i - 1] * (j - i)) - (pre[j] - pre[i - 1]) <= k) << endl;
    }

    // int l = i - 1, r = n + 1;
    // while (r - l > 1) {
    //     int m = (l + r) >> 1;
    //     if ((a[i - 1] * (m - i)) - (pre[m] - pre[i - 1]) <= k) {
    //         l = m;
    //     } else {
    //         r = m;
    //     }
    // }
    // return l;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Let's solve this in a brute force way
    sort(a.begin(), a.end());

    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    auto bs = [&](int i) {
        int l = 0, r = i;

        while (l < r) {
            int m = (l + r) >> 1;
            int cnt = a[i - 1] * (i - m + 1);
            cnt -= (pre[i] - pre[m - 1]);

            if (!(cnt >= 0 && cnt <= k)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        // cout << i << " " << l << endl;
        return l;
    };

    int ans = 0;
    int el = INT_MAX;

    for (int i = n; i >= 1; i--) {
        // search from 1 -- i, for cnt of elements with total transformation <= k
        int j = bs(i);
        if ((i - j + 1) > ans) {
            ans = i - j + 1;
            el = a[i - 1];
        }
    }

    for (int i = n; i >= 1; i--) {
        // search from 1 -- i, for cnt of elements with total transformation <= k
        int j = bs(i);
        if ((i - j + 1) == ans) {
            el = min(el, a[i - 1]);
        }
    }

    cout << ans << " " << el << endl;
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