#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MAX 1000005

int dp(vector<int> &cc, int n, map<int, int> &cache) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    if (cache.count(n) > 0) return cache[n];
    int ans = 0;
    for (auto coin : cc) {
        ans += dp(cc, n - coin, cache);
    }
    return cache[n] = ans;
}

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> cc(c);
    for (int i = 0; i < c; i++) cin >> cc[i];

    map<int, int> cache;
    int ans = dp(cc, n, cache);
    cout << ans << endl;
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
