#include <bits/stdc++.h>
// #define int long long
#define MOD 100000000
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int> count;
    unordered_map<int, int> mp;
    ordered_set ms;

    for (int i = n - 1; i >= 0; i--) {
        count[a[i]]++;
        ms.insert({count[a[i]], a[i]});
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ms.erase({count[a[i]], a[i]});
        count[a[i]] -= 1;
        mp[a[i]] += 1;

        ans += ms.order_of_key({mp[a[i]], 1});
    }

    cout << ans << endl;
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