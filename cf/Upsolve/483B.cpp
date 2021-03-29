#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

bool prime[100006];

const bool sieve = []() {
    memset(prime, true, 100006);
    prime[1] = false;
    prime[0] = false;

    for (int i = 2; i * i <= 100005; i++) {
        if (prime[i]) {
            for (int p = i + i; p <= 100005; p += i) {
                prime[p] = false;
            }
        }
    }
    return true;
}();

void solve() {
    int c1, c2, x, y;
    cin >> c1 >> c2 >> x >> y;

    auto check = [&](int m) {
        int cm1 = max(0LL, c1 - (m / y) + (m / (x * y))), cm2 = max(0LL, c2 - (m / x) + (m / (x * y)));
        m = m - (m / x) - (m / y) + (m / (x * y));

        return m >= cm1 + cm2;
    };

    // for (int i = 826110; i <= 826122; i++) {
    //     cout << i << " " << (check(i) == true ? 1 : 0) << endl;
    // }

    int l = 1,
        r = 2e9 + 1;
    while (l < r) {
        int m = (l + r) >> 1;
        if (!check(m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << l << endl;
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