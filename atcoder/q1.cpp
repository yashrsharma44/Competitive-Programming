#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    set<int> nums;
    for (int a = 2; a * a <= n; a++) {
        int x = a * a;
        while (x <= n) {
            nums.insert(x);
            x *= a;
        }
    }
    cout << n - nums.size() << endl;
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
