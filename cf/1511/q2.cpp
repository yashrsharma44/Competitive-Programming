#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c == 1) {
        for (int i = 0; i < a - 1; i++) cout << 1;
        cout << "3 ";
        for (int i = 0; i < b - 1; i++) cout << 2;
        cout << 4 << endl;
        return;
    }

    for (int i = 0; i < (a - c); i++) {
        cout << 1;
    }
    cout << 3;
    for (int i = 0; i < c - 1; i++) cout << 0;
    cout << " ";
    for (int i = 0; i < (b - c); i++) {
        cout << 2;
    }
    cout << 4;
    for (int i = 0; i < c - 1; i++) cout << 0;
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
