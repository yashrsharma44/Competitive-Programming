#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    auto get = [&](int c, int d) {
        cout << "? " << c << " " << d << endl;
        cout.flush();
        int val;
        cin >> val;
        return val;
    };

    auto print = [&](int a, int b) {
        cout << "! " << a << " " << b << endl;
        cout.flush();
    };

    // check if a > b or not
    int AgrtB = get(0, 0);
    int curA = 0, curB = 0;

    for (int i = 29; i >= 0; i--) {
        int bit = 1 << i;
        int v1 = get(curA ^ bit, curB);
        int v2 = get(curA, curB ^ bit);

        if (v1 != v2) {
            // value are different, so we will have same bit set
            // check if v2 == 1, we will have 1 as set bit
            if (v1 == -1) {
                curA = curA ^ bit;
                curB = curB ^ bit;
            }
            // we skip the else, as it is already set to 0
        } else {
            // values are same, so we put 1 to the biggest number
            if (AgrtB == 1) {
                curA = curA ^ bit;
            } else {
                curB = curB ^ bit;
            }
            AgrtB = v1;
        }
    }

    print(curA, curB);
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