#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

#define MAX 1000005
#define MAXN 200005

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
    int a, b, k;
    cin >> a >> b >> k;

    auto countFac = [&](int num) {
        int count = 0;

        while (num % 2 == 0) {
            num /= 2;
            count++;
        }

        for (int i = 3; i * i <= num; i += 2) {
            while (num % i == 0) {
                count++;
                num /= i;
            }
        }
        if (num > 1) count++;

        return count;
    };

    int cnt = countFac(a) + countFac(b);

    int min_ = -1;
    if (a == b)
        min_ = 0;
    else if (__gcd(a, b) == a || __gcd(a, b) == b)
        min_ = 1;
    else
        min_ = 2;

    if (k >= min_ && k <= cnt && ((min_ == 1 && k == 1) || (k != 1))) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
    seive();
    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}