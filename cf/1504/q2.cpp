#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1')
            pre[i] = 1;
        else
            pre[i] = -1;
    }
    for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
    // for (auto el : pre) cout << el << " ";
    // cout << endl;
    bool flip = false;
    auto check = [&](char c1, char c2, bool flp) {
        if (!flip) return c1 == c2;
        return c1 != c2;
    };
    for (int i = n; i >= 1; i--) {
        if (check(s[i - 1], t[i - 1], flip))
            continue;
        else if (pre[i] == 0)
            flip = !flip;
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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