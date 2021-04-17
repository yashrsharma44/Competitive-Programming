#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

int ncr(int n, int r){
    
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    auto isGood = [&](int num) {
        while (num > 0) {
            int last = num % 10;
            if (last != a || last != b) return false;
            num /= 10;
        }
        return true;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = a * i + (n - i) * b;
        if (isGood(sum)) {
            ans += ncr(n, i);
            ans %= MOD;
        }
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