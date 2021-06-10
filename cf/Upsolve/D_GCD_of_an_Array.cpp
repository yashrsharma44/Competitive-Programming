#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5 + 5, MOD = 1e9 + 7;

int spf[MAXN];

void seive() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

void solve() {
    int n, q, ans = 1;
    cin >> n >> q;

    vector<int> a(n);
    map<int, int> divcount[n];

    map<int, multiset<int>> mp;

    auto add = [&](int i, int x) {
        auto fact = getFactorization(x);
        set<int> f1(fact.begin(), fact.end());

        for (auto f : f1) {
            int pw = 0;
            int cp = x;
            while (cp % f == 0) {
                pw++;
                cp /= f;
            }

            int old_power = divcount[i][f];
            divcount[i][f] += pw;

            int old_min = 0;
            if (mp[f].size() == n) {
                old_min = *mp[f].begin();
            }

            if (old_power != 0) {
                mp[f].erase(mp[f].find(old_power));
            }
            mp[f].insert(old_power + pw);

            if (mp[f].size() == n)
                for (int mul = old_min + 1; mul <= *mp[f].begin(); mul++) {
                    ans *= f;
                    ans %= MOD;
                }
        }
    };

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }

    // cout << ans << endl;

    for (int z = 0; z < q; z++) {
        int i, x;
        cin >> i >> x;
        i--;
        // if (z == 11) {
        //     cout << "p";
        // }
        add(i, x);

        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seive();

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
}