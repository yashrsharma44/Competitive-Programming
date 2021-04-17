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
        // Lets check the number of delta increase required in
        // position to match the fact min(a) >= val

        // we also need to take care of the previous increments if done
        vector<int> st(n, 0);
        int scurr = 0;
        int moves = 0;
        for (int i = 0; i < n; i++) {
            scurr -= i - w >= 0 ? st[i - w] : 0;
            if (val - a[i] - scurr > 0) {
                st[i] = val - a[i] - scurr;
                scurr += st[i];
                moves += st[i];
            }
        }

        // if the total number of increments required for
        // each element is larger than possible, return false
        return moves <= m;
    };

    // for (int i = 1; i <= 11; i++) {
    //     cout << i << "->" << check2(i) << endl;
    // }

    int l = 0,
        r = 2000000001;
    // find the last True
    // lets use the bs: r-l>1
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
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