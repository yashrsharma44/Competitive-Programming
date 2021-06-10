
#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int t;
    cin >> t;
    vector<int> aa(t);
    set<int> keys;
    vector<int> elems(t + 1, 0);
    int mx = 0;
    for (int i = 0; i < t; i++) {
        cin >> aa[i];
        elems[aa[i]]++;
        keys.insert(aa[i]);
        mx = max(mx, aa[i]);
    }

    if (t == 1) {
        cout << "1 1\n";
        cout << "1 1\n";
        return;
    }

    auto check = [&](int n, int m, int x, int y) {
        if (x <= 0 || x > n || y <= 0 || y > m) return false;

        // we know position of 0(x, y), lets place other
        // numbers, and see if that is possible

        vector<int> copy(t + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int el = abs(i - x) + abs(j - y);
                copy[el]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int el = abs(i - x) + abs(j - y);
                if (copy[el] != elems[el]) return false;
            }
        }

        return true;
    };

    int min_el = -1;

    for (int i = 1; i <= t; i++) {
        if (4 * i == elems[i]) continue;
        min_el = i;
        break;
    }
    int b = mx;

    for (int i = 1; i * i <= t; i++) {
        if (t % i != 0) continue;

        int n = i, m = t / i;
        int x = min_el;
        int y = n + m - b - x;

        if (check(n, m, x, y)) {
            cout << n << " " << m << endl;
            cout << x << " " << y << endl;
            return;
        }
        if (check(n, m, y, x)) {
            cout << n << " " << m << endl;
            cout << y << " " << x << endl;
            return;
        }
    }

    cout << -1 << endl;
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