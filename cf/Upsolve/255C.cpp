#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> mp;
    int i = 1;
    for (auto &el : a) {
        if (mp.count(el) == 0)
            mp[el] = i++;
        el = mp[el];
    }

    vector<vector<int>> cache(n + 2, vector<int>(n + 2, -1));

    function<int(int, int)> dp = [&](int i, int last) {
        if (i >= n) return 0LL;
        if (cache[i][last + 1] != -1) return cache[i][last + 1];
        int sum = 0;
        for (int j = i + 1; j < n; j++) {
            if (last == -1) {
                // second element of the series
                sum = max(sum, 1 + dp(j, a[i]));
            } else if (last == a[j]) {
                sum = max(sum, 1 + dp(j, a[i]));
            }
        }
        return cache[i][last + 1] = sum;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, 1 + dp(i, -1LL));
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(j == i+1) cache[i][a[i]] = 1 + dp
        }
    }

    cout << ans << endl;
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