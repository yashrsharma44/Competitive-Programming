#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    //    foolishly, we can make sure that we divide the array
    // into 3 or 2 parts which might return similar no.s
    // The 3 parts was the key, because for 2 parts, the logic is sound
    // but for 3 , if you combine a, a, a -> 0, a the answer would be wrong
    // so we want the answer to stop at 3 parts
    // Why not for 4, because we can combine those to reduce it to 2 :)

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // check for 2 no.s
    vector<int> pre(n, a[0]), suf(n, a.back());
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] ^ a[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] ^ a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (pre[i] == suf[i + 1]) {
            cout << "YES" << endl;
            return;
        }
    }
    // cout << "----" << endl;
    // check for 3
    int inter = 0;
    for (int i = 0; i < n - 2; i++) {
        int inter = a[i + 1];
        for (int j = i + 2; j < n; j++) {
            int prev = pre[i];
            int suff = suf[j];

            if (prev == inter && suff == inter) {
                cout << "YES" << endl;
                return;
            }
            inter ^= a[j];
        }
    }

    cout << "NO" << endl;
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