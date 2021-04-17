#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> odd, eve;
    for (auto el : a) {
        if (el % 2 == 0)
            eve.push_back(el);
        else
            odd.push_back(el);
    }

    for (auto el : odd) {
        cout << el << " ";
    }
    for (auto el : eve) {
        cout << el << " ";
    }
    cout << endl;
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