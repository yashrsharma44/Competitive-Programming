#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        sum += u;
    }
    sum = abs(sum);
    cout << (sum + x - 1) / x << endl;
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