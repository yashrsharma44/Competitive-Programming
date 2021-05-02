#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = LLONG_MAX;
    int orig = 0;
    for (int i = 1; i < n; i++) {
        orig += abs(a[i] - a[i - 1]);
    }
    ans = min(ans, orig);

    // lets change first element
    ans = min(ans, orig - abs(a[1] - a[0]));

    // lets change a[i] to a[i-1] or a[i+1]
    for (int i = 1; i < n - 1; i++) {
        int sum = orig - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]);
        sum += abs(a[i - 1] - a[i + 1]);
        ans = min(ans, sum);
    }

    // lets change last element
    ans = min(ans, orig - abs(a[n - 2] - a[n - 1]));
    cout << ans << endl;
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