#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;
#define MAX 1e7 + 1

void solve() {
    int n, x;
    cin >> n >> x;
    if (n <= x) {
        cout << 1 << endl;
        return;
    }

    int ans = 0;
    if (n % 2 == 1) {
        if (x == 0) {
            cout << -1 << endl;
            return;
        }

        n -= 1;
        x -= 1;
        ans += 1;
    }

    // count bits of n and see how many are in even and odd pos;
    map<int, int> mp;
    for (int i = 0; i <= 31; i++) {
        int el = 1 << i;
        if ((el & n) != 0) {
            if (i % 2 == 0) {
                mp[i - 1] += 2;
            } else {
                mp[i] += 1;
            }
        }
    }
    ans += mp.size();
    while (x > 0) {
        auto el = mp.begin();
        int pw = el->first, cnt = el->second;
        while (x - (1 << pw) > 0 && cnt > 0) {
            x -= (1 << pw);
            cnt -= 1;
            ans -= 1;
        }

        if (x - (1 << pw) < 0) break;
    }
    // cout << "N" << n << " Odd" << o << " Eve" << e << endl;

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