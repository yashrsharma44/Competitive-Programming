#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;

    int min_ = 1, max_ = (int)1e9;

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << rand() % (n - 1 + 1) + 1 << " \n"[i == n - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << rand() % (max_ - min_ + 1) + min_ << " ";
    }
    cout << endl;
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