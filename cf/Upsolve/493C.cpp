#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    set<int> ms;
    for (auto el : a) ms.insert(el);
    for (auto el : b) ms.insert(el);

    int ans = INT_MIN;
    vector<int> res = {-1, -1};

    auto bs = [&](vector<int> &arr, int el) {
        // upper bound
        int l = 0, r = arr.size();
        // return arr[ans] > el
        // first True
        while (l < r) {
            int m = (l + r) >> 1;
            if (!(arr[m] >= el)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    };
    ms.insert((int)(2 * 1e9));
    for (auto el : ms) {
        // binary search for the position
        int i1 = bs(a, el);
        int a1 = 0, b1 = 0;

        a1 += i1 * 2 + (a.size() - i1) * 3;

        int i2 = bs(b, el);
        b1 += i2 * 2 + (b.size() - i2) * 3;

        ans = max(ans, a1 - b1);
    }

    for (auto el : ms) {
        // binary search for the position
        int i1 = bs(a, el);
        int a1 = 0, b1 = 0;

        a1 += i1 * 2 + (a.size() - i1) * 3;

        int i2 = bs(b, el);
        b1 += i2 * 2 + (b.size() - i2) * 3;

        if (a1 - b1 == ans) {
            if (a1 > res[0]) {
                res = {a1, b1};
            }
        }
    }
    cout << res[0] << ":" << res[1] << endl;
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