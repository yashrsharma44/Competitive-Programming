#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int v;
    cin >> v;
    vector<int> a(10);
    for (int i = 1; i <= 9; i++) cin >> a[i];

    int mn = INT_MAX, mni = -1;
    for (int i = 1; i <= 9; i++) {
        if (a[i] <= mn) {
            mn = a[i];
            mni = i;
        }
    }

    if (v < mn) {
        cout << -1 << endl;
        return;
    }

    int rem = v % mn;
    int q = v / mn;
    vector<int> ans;
    for (int i = 0; i < q; i++) ans.push_back(mni);

    int total = q * a[mni];
    for (int i = 0; i < q; i++) {
        for (int j = 9; j > mni; j--) {
            if (v - total + a[mni] >= a[j]) {
                ans[i] = j;
                total -= a[mni];
                total += a[j];
                break;
            }
        }
    }
    for (auto el : ans) cout << el;
    cout << endl;
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