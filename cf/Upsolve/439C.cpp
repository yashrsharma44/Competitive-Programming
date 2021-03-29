#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }

    int odd_count = k - p;
    int even_count = p;

    // if odd available nos < odd count
    if (odd.size() < odd_count) {
        cout << "NO" << endl;
        return;
    }

    // if parity not same, not possible
    if ((odd.size() - odd_count) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    // if even available nos < even count
    if ((even.size() < even_count) && (odd.size() != 2 * even_count)) {
        cout << "NO" << endl;
        return;
    }

    bool useOdd = false;
    // check if we need to use odd nos.
    if ((even.size() < even_count) && (odd.size() == 2 * even_count)) {
        useOdd = true;
    }

    cout << "YES" << endl;

    // lets print all even nos
    if (!useOdd) {
        for (int i = 0; i < even_count - 1; i++) {
            cout << 1 << " " << a[even[i]] << endl;
        }
        if ((even.size() - even_count + 1) > 0)
            cout << (even.size() - even_count + 1) << " ";
        else
            cout << even_count * 2 << " ";
        for (int i = even_count - 1; i < even.size(); i++) {
            cout << a[even[i]] << " ";
        }
        cout << endl;

    } else {
        for (int i = 0; i < even_count; i++) {
            int i1 = odd.back();
            odd.pop_back();
            int i2 = odd.back();
            odd.pop_back();
            cout << 2 << " " << a[i1] << " " << a[i2] << endl;
        }
    }

    if (odd.size() == 0) return;
    // lets print all odd nos
    for (int i = 0; i < odd_count - 1; i++) {
        cout << 1 << " " << a[odd[i]] << endl;
    }
    cout << (odd.size() - odd_count + 1) << " ";
    for (int i = odd_count - 1; i < odd.size(); i++) {
        cout << a[odd[i]] << " ";
    }
    cout << endl;
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