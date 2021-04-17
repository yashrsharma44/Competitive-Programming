#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;
#define MAX 1e7 + 1

int spf[(int)(MAX)];

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAX; i++) spf[i] = i;

    for (int i = 4; i < MAX; i += 2) {
        spf[i] = 2;
    }

    for (int i = 3; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> factorization(int el) {
    set<int> ans;
    while (el > 1) {
        ans.insert(spf[el]);
        el /= spf[el];
    }
    return vector<int>(ans.begin(), ans.end());
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin >> m;
    vector<vector<int>> q(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        q[i] = {u, v};
    }
    vector<int> pre(MAX, 0);
    for (auto el : a) {
        auto fact = factorization(el);
        for (auto f : fact) {
            pre[f] += 1;
        }
    }
    for (int i = 1; i < MAX; i++) {
        pre[i] += pre[i - 1];
    }

    for (auto qq : q) {
        int l = qq[0], r = qq[1];
        l = min(l, (int)MAX - 1LL);
        r = min(r, (int)MAX - 1LL);

        int ans = pre[r] - pre[l - 1];
        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    int t;
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
}