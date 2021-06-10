#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int bob = 0, alice = 0;
    int zero = 0;

    for (auto ch : s) {
        if (ch == '0') zero++;
    }

    if (zero == 1 || zero % 2 == 0) {
        cout << "BOB" << endl;
        return;
    }

    if (zero % 2 == 1) {
        cout << "ALICE" << endl;
    } else {
        cout << "BOB" << endl;
    }

    // if (zero % 2 == 1 && n != 1) {
    //     cout << "ALICE" << endl;
    // } else if (zero == 0) {
    //     cout << "DRAW" << endl;
    // } else {
    //     cout << "BOB" << endl;
    // }
    return;
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