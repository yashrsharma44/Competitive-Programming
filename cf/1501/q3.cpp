#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int> > mp(5000005, vector<int>(2, -1));
    for (int i = 0; i < min(n, (int)(3 * 1e6)); i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            if (mp[sum][0] > 0) {
                int i1 = mp[sum][0], j1 = mp[sum][1];
                if (i1 != i + 1 && i1 != j + 1 && j1 != i + 1 && j1 != j + 1) {
                    cout << "YES"
                         << "\n";
                    cout << i + 1 << " " << j + 1 << " " << i1 << " " << j1 << "\n";
                    return;
                }
            }
            mp[sum][0] = i + 1;
            mp[sum][1] = j + 1;
        }
    }
    cout << "NO"
         << "\n";
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