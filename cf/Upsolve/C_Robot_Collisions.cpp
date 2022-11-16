#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> type(n);
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        type[i] = (cc == 'L' ? 1 : -1);
    }

    vector<int> ans(n, -1);
    for (int par = 0; par <= 1; par++) {
        vector<vector<int>> ds;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == par) {
                ds.push_back({a[i], i});
            }
        }

        sort(ds.begin(), ds.end());

        // lets use a stack to check if a left going element clashes with
        // a right going element in a stack
        vector<int> st;
        for (auto el : ds) {
            int i = el[1];
            int dir = type[i];

            if (dir == 1) {
                if (st.empty()) {
                    st.push_back(i);
                } else {
                    int j = st.back();
                    st.pop_back();

                    ans[i] = ans[j] = (a[i] - (type[j] == -1 ? a[j] : -a[j])) / 2;
                }
            } else {
                st.push_back(i);
            }
        }

        // consume all the elements from the stack
        while (st.size() > 1) {
            int i = st.back();
            st.pop_back();
            int j = st.back();
            st.pop_back();

            ans[i] = ans[j] = (2 * m - a[i] - (type[j] == -1 ? a[j] : -a[j])) / 2;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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