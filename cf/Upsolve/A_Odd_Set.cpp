#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // count even and odd to be same
    int e = 0;
    for (auto el : a) {
        if (el % 2 == 0) e++;
    }

    if (e * 2 != n) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
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