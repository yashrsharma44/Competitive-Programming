#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> elems;
    for (auto el : a) elems.insert(el);

    if (elems.size() > k) {
        cout << -1 << endl;
        return;
    }
    cout << n * k << endl;
    for (int i = 0; i < n; i++) {
        for (auto el : elems) cout << el << " ";
        for (int i = 1; i <= (k - elems.size()); i++) cout << "1 ";
    }
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