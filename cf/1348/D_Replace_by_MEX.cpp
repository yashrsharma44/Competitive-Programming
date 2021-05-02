#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> mex;
    map<int, set<int>> mapPos;

    for (int i = 0; i <= 2 * n; i++) {
        mex.insert(i);
    }
    for (int i = 0; i < n; i++) {
        mapPos[a[i]].insert(i);
        mex.erase(a[i]);
    }

    auto calMex = [&](vector<int> b) {
        set<int> elems;
        for (auto el : b) elems.insert(el);
        for (int i = 0; i <= n; i++) {
            if (elems.count(i) == 0) return i;
        }
        return n;
    };
    vector<int> ans;
    set<int> unfixed;
    for (int i = 0; i < n; i++) {
        if (a[i] != i) unfixed.insert(i);
    }
    while (unfixed.size() > 0) {
        int i = *unfixed.begin();
        if (a[i] == i) {
            unfixed.erase(i);
            continue;
        }
        if (calMex(a) == n) {
            a[i] = calMex(a);
            ans.push_back(i);
        }
        int pos = calMex(a);

        a[pos] = pos;
        ans.push_back(pos);
        unfixed.erase(pos);
    }

    assert(ans.size() <= 2 * n);
    cout << ans.size() << endl;
    for (auto el : ans) cout << el + 1 << " ";
    cout << endl;
    // for (auto el : a) cout << el << " ";
    // cout << endl;
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