#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> elems;
    for (auto el : a) elems.insert(el);
    if (elems.size() == 1) {
        cout << "YES" << endl;
        return;
    }
    vector<int> suf({a.back()});
    for (int i = n - 2; i >= 0; i--) {
        suf.push_back(suf.back() ^ a[i]);
    }
    reverse(suf.begin(), suf.end());
    int pre = a[0];
    for (int i = 1; i < n; i++) {
        // cout << i << " " << pre << " " << suf[i] << endl;
        if (pre == suf[i]) {
            cout << "YES" << endl;
            return;
        }
        pre ^= a[i];
    }
    cout << "NO" << endl;
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