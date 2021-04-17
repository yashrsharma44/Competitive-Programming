#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = LLONG_MAX;
    auto check = [&](vector<int> &b) {
        int min_ = LLONG_MAX, max_ = LLONG_MIN;
        int count = 0;
        for (auto el : b) {
            min_ = min(min_, el);
            max_ = max(max_, el);
            int local = max_ - min_;
            count += local;
        }
        return count;
    };
    vector<int> aa;
    // cout << check(aa) << endl;
    do {
        if (check(a) < ans) {
            ans = check(a);
            aa = a;
        }
        // for (auto el : a) cout << el << " ";
        // cout << endl;
    } while (next_permutation(a.begin(), a.end()));

    for (auto el : aa) cout << el << " ";
    cout << endl
         << check(aa) << endl;
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