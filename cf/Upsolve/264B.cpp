#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> res;
    auto bs = [&](int el) {
        int l = 0, r = res.size();
        // find the first True
        // res[ans] >= el and gcd(ans, el) > 1
        while (l < r) {
            int m = (l + r) >> 1;
            if (res[m] > el && __gcd(res.back(), el) > 1) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    };

    // LIS
    for (auto el : a) {
        int id = bs(el);
        if (id == res.size())
            res.push_back(el);
        else {
            res[id] = el;
        }
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