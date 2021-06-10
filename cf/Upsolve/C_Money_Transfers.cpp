#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == 0)
            pre[i] = a[i];
        else
            pre[i] += pre[i - 1] + a[i];
    }

    // find the max occurrence of a prefix value, we can
    // split our group into max possible such prefix values,
    // and our answer = total_sum - number of groups
    map<int, int> mp;
    for (auto el : pre) mp[el]++;

    int cnt = 0;
    for (auto el : mp) {
        cnt = max(cnt, el.second);
    }

    cout << n - cnt << endl;
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