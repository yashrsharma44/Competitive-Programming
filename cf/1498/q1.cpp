#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

int sum(int num) {
    int tot = 0;
    while (num > 0) {
        tot += num % 10;
        num /= 10;
    }
    return tot;
}

void solve() {
    int n;
    cin >> n;
    int i = n;
    while (true) {
        if (__gcd(i, sum(i)) > 1) {
            cout << i << endl;
            return;
        }
        i++;
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