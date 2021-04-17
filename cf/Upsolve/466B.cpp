#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a * b >= 6 * n) {
        cout << a * b << endl
             << a << " " << b << endl;
        return;
    }

    bool swapped = false;
    n *= 6;
    if (a > b) {
        swap(a, b);
        swapped = true;
    }

    int ans = LLONG_MAX;
    int aa1 = a, bb1 = b;
    for (int i = a; i * i <= n; i++) {
        int j = (n + i - 1) / i;
        if (i >= a && j >= b && i * j >= n && i * j < ans) {
            ans = i * j;
            aa1 = i;
            bb1 = j;
        }
    }
    cout << aa1 * bb1 << endl;
    if (!swapped)
        cout << aa1 << " " << bb1 << endl;
    else
        cout << bb1 << " " << aa1 << endl;

    return;
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