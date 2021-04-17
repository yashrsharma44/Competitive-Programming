#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<int> ms;
    for (auto el : a) ms.insert(el);

    int cnt = 0, c = w;
    while (!ms.empty()) {
        auto it = ms.upper_bound(c);
        if (it == ms.begin()) {
            c = w;
            cnt++;
        } else {
            it = prev(it);
            c -= *it;
            ms.erase(it);
        }
    }
    cout << cnt + 1 << endl;
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