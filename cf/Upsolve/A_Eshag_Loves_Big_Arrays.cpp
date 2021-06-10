#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int min_ = a[0];
    for (int el : a) {
        min_ = min(min_, el);
    }
    int cnt = 0;
    for (auto el : a) {
        if (el == min_) cnt++;
    }

    cout << (n - cnt) << endl;
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