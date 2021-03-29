#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n, m;
    n = a.length();
    m = b.length();
    int ans = n + m;
    for (int i = 0; i < n; i++) {
        string s1 = "";
        for (int j = i; j < n; j++) {
            s1 += a[j];

            for (int k = 0; k < m; k++) {
                string s2 = "";
                for (int l = k; l < m; l++) {
                    s2 += b[l];

                    if (s1 == s2) {
                        int cnt = n + m - s1.length() - s2.length();
                        ans = min(ans, cnt);
                    }
                }
            }
        }
    }

    cout << ans << endl;
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