#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    vector<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47});

    auto divisible = [&](int num) {
        cout << num << endl;
        fflush(stdout);
        string res;
        cin >> res;
        return res == "yes";
    };
    // just check if there are 2 el from primes, divide our number
    // if yes, composite else prime
    int count = 0;
    for (int i = 0; i < primes.size(); i++) {
        if (divisible(primes[i])) {
            count++;
            if (primes[i] * primes[i] <= 100 && divisible(primes[i] * primes[i]))
                count++;
        }
    }

    if (count >= 2)
        cout << "composite" << endl;
    else
        cout << "prime" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
}