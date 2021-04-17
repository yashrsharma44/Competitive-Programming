#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int k = r - l + 1;
    auto pre = [&](int m) {
        return (m * (m + 1)) / 2;
    };
    auto sum = [&](int l, int r) {
        return pre(r) - pre(l - 1);
    };

    if (pre(k) > s || s > sum(n - k + 1, n)) {
        cout << -1 << endl;
        return;
    }
    set<int> elems;
    for (int i = 1; i <= n; i++) elems.insert(i);
    vector<int> ans(n + 1);
    int id = -1;
    for (int i = 1; i <= n - k + 1; i++) {
        if (sum(i, i + k - 1) <= s) id = i;
    }

    int a = id + k;
    int sm = sum(id, id + k - 1);
    int z = r;
    while (z >= l && sm < s) {
        sm -= (a - 1);
        sm += a;
        ans[z] = a;
        a -= 1;
        z -= 1;
    }
    for (int i = l; i <= z; i++) ans[i] = id++;

    for (int i = l; i <= r; i++) {
        elems.erase(ans[i]);
    }
    for (int i = 1; i < l; i++) {
        ans[i] = *elems.begin();
        elems.erase(ans[i]);
    }
    for (int i = r + 1; i <= n; i++) {
        ans[i] = *elems.begin();
        elems.erase(ans[i]);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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
