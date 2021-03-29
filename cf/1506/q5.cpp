#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> q(n);
    set<int> non;
    non.insert(0);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        non.insert(q[i]);
    }

    set<int> mis;
    for (int i = 1; i <= n; i++) {
        if (non.count(i) == 0)
            mis.insert(i);
    }

    int prev = q[0];
    for (int i = 1; i < n; i++) {
        if (q[i] == prev) {
            q[i] = -1;
        } else {
            prev = q[i];
        }
    }

    cout << q[0] << " ";
    for (int i = 1; i < n; i++) {
        if (q[i] == -1) {
            int val = *mis.begin();
            cout << val << " ";
            mis.erase(val);
        } else {
            cout << q[i] << " ";
        }
    }
    cout << endl;

    int i = n - 1;
    int mx, nextM;
    set<int> elems;
    while (i >= 0) {
        if (q[i] == -1) {
            while (elems.size() == 0) {
                mx = *non.rbegin();
                non.erase(mx);
                nextM = *non.rbegin();

                for (int z = nextM + 1; z < mx; z++) elems.insert(z);
            }
            q[i] = *elems.begin();
            elems.erase(q[i]);
        }
        i -= 1;
    }

    for (auto el : q) cout << el << " ";
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