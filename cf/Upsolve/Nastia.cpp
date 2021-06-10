#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n;
    cin >> n;

    auto get = [&](int t, int i, int j, int x) {
        cout << "? " << t << " " << i << " " << j << " " << x << endl;
        cout.flush();
        int val;
        cin >> val;
        return val;
    };

    vector<int> ans(n + 1, -1);

    auto print = [&]() {
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
        cout.flush();
    };

    // lets find the pos of the max element
    // by scanning the adjacent elements, pair at a time
    int pos_n = -1;
    for (int i = 1; i <= n - 1; i += 2) {
        int el = get(1, i, i + 1, n - 1);

        // if el == n or n - 1, we have a possible candidate for the i, i+1th value
        // to be maximum

        // if el == n, we have i+1 as the max answer

        if (el == n) {
            pos_n = i + 1;
            break;
        }

        if (el == n - 1) {
            // check if i can be the possible answer
            int el2 = get(1, i + 1, i, n - 1);
            if (el2 == n) {
                pos_n = i;
                break;
            }
        }
    }
    if (pos_n == -1 && n % 2 == 1) pos_n = n;
    // cout << "Y" << endl;

    // we should find the pos of n
    assert(pos_n != -1);

    ans[pos_n] = n;
    // lets find the pos of other elements :)
    for (int i = 1; i <= n; i++) {
        if (i == pos_n) continue;
        int el = get(2, i, pos_n, 1);
        ans[i] = el;
    }

    print();
}

int32_t main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}