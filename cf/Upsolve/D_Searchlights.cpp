#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    for (int i = 0; i < m; i++) cin >> c[i] >> d[i];

    // lets keep a line sweep to store the max dy we need to go
    // for each x
    vector<int> events(1e6 + 5, 0);
    int mx = 0;
    bool isEmpty = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int dx = c[j] - a[i];
            int dy = d[j] - b[i];

            // if search light is ahead of the robber
            if (dx >= 0) {
                // make sure the dy is positive, else
                // the robbber is ahead of searchlight
                events[dx] = max(events[dx], max(dy + 1, 0LL));
                mx = max(mx, dx);
                isEmpty = true;
            }
        }
    }
    if (!isEmpty) {
        // all robbers are safe :P
        cout << 0 << endl;
        return;
    }
    // for (auto &[k, v] : events) {
    //     cout << k << " " << v << endl;
    // }

    // do a sweep line from right to left, taking the min(dx + events[dx])
    int ans = mx + 1;
    int last = 0;
    for (int i = mx; i >= 0; i--) {
        if (events[i] > 0) last = max(last, events[i]);
        ans = min(ans, i + last);
        // cout << "[" << i << " " << last << "]: "
        //      << "->" << i + last << endl;
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