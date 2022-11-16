#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    ll i, n = s.length();

    if (n == 2) {
        cout << 0 << endl;
        return;
    }

    auto solver = [&](string& A) {
        ll i = 1;

        vector<vector<ll> > cache(n, vector<ll>(26));

        cache[0][A[0] - 'a'] = 1;

        while (i < n) {
            ll prev = 0;
            for (auto x : cache[i - 1]) {
                prev += x;
                prev %= MOD;
            }
            if (A[i] == '?') {
                int j = 0;
                while (j < 26) {
                    cache[i][j] += (prev - cache[i - 1][j]) % MOD;
                    cache[i][j] %= MOD;
                    cache[i][j] += MOD;
                    cache[i][j] %= MOD;
                    j++;
                }
            } else {
                cache[i][A[i] - 'a'] = (prev - cache[i - 1][A[i] - 'a']) % MOD;
                cache[i][A[i] - 'a'] %= MOD;
                cache[i][A[i] - 'a'] += MOD;
                cache[i][A[i] - 'a'] %= MOD;
            }
            i++;
        }

        ll ans = 0;
        for (auto x : cache[n - 1]) {
            ans += x;
            ans %= MOD;
        }
        return ans;
    };

    if (s[0] == '?' || s[n - 1] == '?') {
        if (s[0] == '?' && s[n - 1] == '?') {
            // 26 cases
            ll ans = 0;
            int i = 0;
            while (i < n) {
                s[0] = s[n - 1] = 'a' + i;
                ans += solver(s);
                ans %= MOD;
                i++;
            }
            cout << ans << endl;
        } else if (s[0] == '?') {
            s[0] = s[n - 1];
            // 1 case cache
            cout << solver(s) << endl;
        } else {
            s[n - 1] = s[0];
            // 1 case cache;
            cout << solver(s) << endl;
        }
    } else {
        if (s[0] == s[n - 1]) {
            // 1 case cache
            cout << solver(s) << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int main() {
    ll t;
    cin >> t;

    while (t--) solve();
}

for (i = 1..i <2* n) {
    a[i] = min(a[i%n], a[i - 1 %n] + x);
}

sum(a)
