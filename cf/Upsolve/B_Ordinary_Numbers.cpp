#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    int i = 0;
    for (i = 10; i <= n; i *= 10) {
        cnt += 9;
    }

    int len = to_string(n).length();
    for (int i = 1; i <= 9; i++) {
        string t = "";
        for (int j = 0; j < len; j++) {
            t += to_string(i);
        }

        if (stoll(t) <= n)
            cnt++;
        else
            break;
    }

    cout << cnt << endl;
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