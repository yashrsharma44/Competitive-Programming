#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for (auto el : a) sum += el;
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }

    // sum even, contain atleast 1 odd
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            cout << 1 << endl;
            cout << i + 1 << endl;
            return;
        }
    }

    // sum even, contains all even
    // lets remove 1 element whose el % 4 != 0
    for (int i = 0; i < n; i++) {
        if (a[i] % 4 != 0) {
            cout << 1 << endl;
            cout << i + 1 << endl;
            return;
        }
    }

    // all divisible by 4, remove all
    
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