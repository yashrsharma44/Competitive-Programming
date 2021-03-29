#include <bits/stdc++.h>
#define int unsigned long long
#define MOD 100000000
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    // find a position such that R[p] != L[p], because bits from max-bits(L, R) - p are going to be common for all R<=num<=L
    // then we can switch digits after p, with max value of 1

    string ll = "", rr = "";
    while (l > 0) {
        ll += to_string(l % 2);
        l /= 2;
    }
    while (r > 0) {
        rr += to_string(r % 2);
        r /= 2;
    }
    while (ll.length() < rr.length()) {
        ll += "0";
    }

    reverse(ll.begin(), ll.end());
    reverse(rr.begin(), rr.end());
    // cout << ll << "\n"
    //      << rr << endl;
    // cout << ll.length() << endl;

    int p = -1;
    for (int i = 0; i < ll.length(); i++) {
        if (ll[i] != rr[i]) {
            p = i;
            break;
        }
    }
    if (p == -1) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < ll.length(); i++) {
        if (i < p) {
            ans |= 0;
        } else {
            ans |= 1;
        }
        ans <<= 1;
    }
    cout << (ans >> 1) << endl;
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