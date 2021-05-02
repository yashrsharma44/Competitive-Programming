#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    auto get = [=](string aa) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ans[i + 1] = aa[i] - 'a';
        }
        return ans;
    };

    vector<int> a = get(s), b = get(t);
    // add two numbers
    for (int i = n; i >= 0; i--) {
        a[i] += b[i];
        if (i != 0) {
            a[i - 1] += a[i] / 26;
            a[i] %= 26;
        }
    }

    // divide two numbers
    for (int i = 0; i <= n; i++) {
        int rem = a[i] % 2;
        a[i] /= 2;

        if (i + 1 <= n) {
            a[i + 1] += 26 * rem;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (char)(a[i] + 'a');
    }
    cout << endl;
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