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

    // If we can move the max/min of the subarray to the last, the discrepancy would be minimized
    // this reequires us to chose some combination of numbers as the last element subsequently for building the array
    // or in other words -
    // [...,a1,a2,a3], here we have the option to chose one element(min, max) as the next element
    // a dp solution would work in this case
    vector<vector<int>> cache(2000, vector<int>(2000, -1));

    function<int(int, int)> dp = [&](int l, int r) {
        if (l >= r) return 0LL;
        if (cache[l][r] != -1) return cache[l][r];

        int sum = a[r] - a[l];
        return cache[l][r] = min(sum + dp(l + 1, r), sum + dp(l, r - 1));
    };

    cout << dp(0, n - 1) << endl;
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