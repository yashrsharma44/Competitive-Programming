#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;
int cnt[100005];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](int k) {
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (auto el : a) cnt[el]++;

        set<vector<int>, greater<vector<int>>> elems;
        for (auto el : a) {
            elems.insert({cnt[el], el});
        }

        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (i >= k && cnt[b[i - k]] > 0) {
                elems.insert({cnt[b[i - k]], b[i - k]});
            }
            if (elems.size() == 0) return false;
            auto entry = *elems.begin();
            b.push_back(entry[1]);
            cnt[entry[1]]--;
            elems.erase(entry);
        }
        return true;
    };
    // for (int i = 1; i < 10; i++) {
    //     cout << i << " " << check(i) << endl;
    // }
    // last True
    int l = 0, r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l - 1 << endl;
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