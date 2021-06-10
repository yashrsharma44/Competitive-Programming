#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    multiset<int> ms;
    ms.insert(b[0]);

    auto midPointer = ms.begin();

    for (int i = 1; i < n; i++) {
        if (b[i] < *midPointer) {
            // insert if only one element
            // or the prev element to mid
            // is smaller than b[i]
            if (midPointer == ms.begin() || *prev(midPointer) < b[i]) {
                ms.insert(b[i]);
                --midPointer;
            }
            // if the prev element is same as b[i], dont insert
            else if (*prev(midPointer) == b[i]) {
                --midPointer;
            } else {
                cout << "NO" << endl;
                return;
            }
        } else if (b[i] > *midPointer) {
            if (next(midPointer) == ms.end() || *next(midPointer) > b[i]) {
                ms.insert(b[i]);
                ++midPointer;
            } else if (*next(midPointer) == b[i]) {
                ++midPointer;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}