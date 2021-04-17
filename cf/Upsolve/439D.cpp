#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    set<int> elems;
    int min_ = INT_MAX, max_ = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        elems.insert(a[i]);
        min_ = min(min_, a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        elems.insert(b[i]);
        max_ = max(max_, b[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> prea({0}), preb({0});
    for (auto el : a) {
        prea.push_back(prea.back() + el);
    }

    for (auto el : b) {
        preb.push_back(preb.back() + el);
    }
    int ans = LLONG_MAX;

    auto bs1 = [&](vector<int> &arr, int k) {
        // find the first element <= k
        // first True
        // array[ans] <= k
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] <= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };

    auto check = [&](int val) {
        int total = 0;
        int pos1 = bs1(a, val);

        pos1--;
        if (pos1 >= 0) {
            total += val * (pos1 + 1) - prea[pos1];
        }
        int ss = total;
        cout << "SS: " << ss << " pos1: " << pos1 << endl;
        int pos2 = bs1(b, val);
        pos2--;
        if (pos2 >= 0) {
            total += (preb[m] - preb[pos2]) - (m - pos2 - 1) * val;
        } else {
            total += (preb[m]) - m * val;
        }
        return total;
    };

    for (auto el : elems) {
        // if (check(el) >= 0)
        ans = min(ans, check(el));
    }

    // for (auto el : elems) {
    //     if (ans == check(el)) {
    //         cout << el << endl;
    //     }
    // }

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