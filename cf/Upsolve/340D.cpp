#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // LIS for the answer
    // graph wont have edges if the values are increasing
    // in order
    vector<int> res;

    auto bs = [&](int val) {
        // find the element, res[ans] >= val,
        // first true

        int l = 0, r = res.size();
        while (l < r) {
            int m = (l + r) >> 1;
            if (!(res[m] >= val)) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    };

    for (auto el : a) {
        int i = bs(el);
        if (i == res.size()) res.push_back(el);
        res[i] = el;
    }

    cout << res.size() << endl;
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