#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int last = p[0];
    vector<int> arr({last});
    set<int> elems;
    for (int i = 1; i < n; i++) {
        if (last == p[i]) {
            arr.push_back(0);
            continue;
        }

        last = p[i];
        arr.push_back(last);
    }

    for (int i = 1; i <= n; i++) elems.insert(i);
    for (auto el : arr) elems.erase(el);

    vector<int> minarr(arr.begin(), arr.end()), maxarr(arr.begin(), arr.end());

    // fill minarr
    for (int i = 0; i < n; i++) {
        if (minarr[i] == 0) {
            minarr[i] = *elems.begin();
            elems.erase(minarr[i]);
        }
    }

    for (int i = 1; i <= n; i++) elems.insert(i);
    for (auto el : arr) elems.erase(el);

    // fill maxarr
    vector<int> rem(elems.begin(), elems.end());

    auto bs = [&](int lastBig) {
        // last True
        // rem[ans] < maxarray[idx]
        int l = -1, r = rem.size() - 1;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (rem[m] <= lastBig)
                l = m;
            else
                r = m - 1;
        }
        int el = rem[l];
        rem.erase(rem.begin() + l);
        return el;
    };

    int lastBig = 0;
    for (int i = 0; i < n; i++) {
        if (maxarr[i] != 0) {
            lastBig = max(lastBig, maxarr[i]);
            continue;
        }

        // find last el < maxarr[i]
        // last True
        maxarr[i] = bs(lastBig);
    }
    for (auto el : minarr) cout << el << " ";
    cout << endl;
    for (auto el : maxarr) cout << el << " ";
    cout << endl;
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