#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;
#define pi acos(-1)
int d;
int cache[30005][500];

int dp(multiset<int> &a, int cur, int l) {
    int max_ = *a.rbegin();
    if (cur > max_) return 0;
    int ll = l - (d - 250);
    if (cache[cur][ll] != -1) return cache[cur][ll];

    int ans = 0;

    if (l != 1) {
        ans = max(ans, dp(a, cur + l - 1, l - 1));
    }
    ans = max({ans, dp(a, cur + l, l), dp(a, cur + l + 1, l + 1)});
    return cache[cur][ll] = ans + (a.count(cur));
}

void solve() {
    int n;
    cin >> n >> d;
    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        a.insert(u);
    }
    for (int i = 0; i < 30005; i++) {
        for (int j = 0; j < 500; j++) {
            cache[i][j] = -1;
        }
    }
    cout << dp(a, d, d) << endl;
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