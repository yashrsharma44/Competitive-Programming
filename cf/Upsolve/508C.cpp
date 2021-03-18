#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int m, t, r;
    cin >> m >> t >> r;
    vector<int> w(m);
    for (int i = 0; i < m; i++) cin >> w[i];

    vector<int> events(305);
    for (int i = 0; i < m; i++) {
        events[w[i] - 1] += 1;
        events[w[i] + t + 1] -= 1;
    }
    for (int i = 1; i < 305; i++) {
        events[i] += events[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < 305; i++) {
        ans = max(ans, events[i]);
    }
    cout << ans + r - 1 << endl;
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