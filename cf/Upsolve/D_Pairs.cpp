#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    int min_ = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        min_ = min(min_, b[i]);
    };

    set<int> unused;
    for (int i = 1; i <= 2 * n; i++) unused.insert(i);
    for (auto el : b) unused.erase(el);
    sort(b.begin(), b.end());
    vector<int> ans(unused.begin(), unused.end());
    // for each position, we find the pos of the min element
    // which is greater than b[i], and check if we can leverage
    // those elements to pass b[i] as minimum

    auto bs = [&](vector<int> &arr, int el) {
        // find element which >= el
        // first True
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) >> 1;
            if (arr[m] >= el)
                r = m;
            else
                l = m + 1;
        }
        return l;
    };

    // int count = min_ > *ans.rbegin() ? 1 : 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        int el = b[i];
        int idx = bs(ans, el);
        if (idx == n) {
            break;
        }
        if (i + 1 <= n - idx) {
            l++;
        } else {
            break;
        }
    }

    int r = 0;
    for (int i = 0; i < n; i++) {
        int el = ans[i];
        int idx = bs(b, el);
        if (idx == n) break;
        if (i + 1 <= n - idx) {
            r++;
        } else
            break;
    }
    r = n - r + 1;
    cout << l - (n - r) + 1 << endl;
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