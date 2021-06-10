
#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> pre;

    auto remove = [&](int el) {
        if (pre.count(el) == 0) return;
        pre[el]--;
        if (pre[el] == 0) pre.erase(el);
    };

    for (int el : a) pre[el]++;

    int ans = 0;
    set<int> suf;

    for (int i = n - 1; i >= 0; i--) {
        remove(a[i]);
        if (suf.count(a[i]) != 0) continue;

        suf.insert(a[i]);
        ans += pre.size();
    }

    cout << ans << endl;
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