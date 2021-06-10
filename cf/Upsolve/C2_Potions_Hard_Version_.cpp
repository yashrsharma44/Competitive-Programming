#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

int cache[2005][2005];

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<int> ms;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ms.insert(a[i]);

        if (a[i] >= 0) continue;

        while (sum < 0 && ms.size() > 0) {
            int min_ms = *ms.begin();
            ms.erase(ms.find(min_ms));
            sum -= min_ms;
        }
    }

    cout << ms.size() << endl;
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