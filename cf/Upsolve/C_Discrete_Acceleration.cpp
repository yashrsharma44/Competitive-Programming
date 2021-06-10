#include <bits/stdc++.h>
// #define int long long
#define MOD 100000007
using namespace std;

void solve() {
    long double n, l;
    cin >> n >> l;
    vector<long double> a(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = l;

    if (n == 1) {
        long double t = min(a[1], l - a[1]);
        long double x1 = 0.0, x2 = l;

        long double mid = l / 2.0;
        if (a[1] > mid) {
            x2 = a[1];
            x1 += t;
        } else {
            x1 = a[1];
            x2 -= t;
        }

        long double t2 = abs(x2 - x1) / (3.0);
        // cout <<setprecision(15)<< t << endl;
        cout << t + t2 << endl;
        return;
    }
    n += 2;
    vector<long double> pre(n, 0), suf(n, 0);

    long double speed = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            speed++;
        } else {
            pre[i] += pre[i - 1] + ((a[i] - a[i - 1]) / speed);
            speed++;
        }
    }

    speed = 0;
    for (long double i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            speed++;
        } else {
            suf[i] += suf[i + 1] + ((a[i + 1] - a[i]) / speed);
            speed++;
        }
    }

    // for (auto el : pre) {
    //     cout << el << " ";
    // }
    // cout << endl;
    // for (auto el : suf) {
    //     cout << el << " ";
    // }
    // cout << endl;

    // lets consider all the position a[i], a[i+1] and check if they
    // can be our candidate answer

    for (int i = 0; i < n - 1; i++) {
        long double t1 = pre[i];
        long double t2 = suf[i + 1];
        int idx = i + 1;
        long double s1 = idx - 0, s2 = (n + 1) - (idx + 1);
        // cout << s1 << "->>" << s2 << endl;
        // cout << std::setprecision(15)<<t1 << " " << t2 << endl;

        // lets move the smaller one towards the bigger time one
        if (t1 < t2) {
            // move t1 to t2
            long double delta = s1 * (t2 - t1);
            if (a[i] + delta <= a[i + 1]) {
                // we can consider this as a prospective answer
                long double x1 = a[i] + delta, x2 = a[i + 1];
                long double t3 = (x2 - x1) / (s1 + s2);
                t3 += t2;
                cout << t3 << endl;
                return;
            }
        } else if (t1 > t2) {
            // move t2 to t1
            long double delta = s2 * (t1 - t2);
            // cout << a[i] + delta << " " << a[i + 1] << endl;
            if (a[i] + delta <= a[i + 1]) {
                // we can consider this as a prospective answer
                long double x1 = a[i], x2 = a[i + 1] - delta;
                long double t3 = (x2 - x1) / (s1 + s2);
                t3 += t1;
                cout << t3 << endl;
                return;
            }
        } else {
            long double x1 = a[i], x2 = a[i + 1];
            long double t3 = (x2 - x1) / (s1 + s2);
            t3 += t1;
            cout << t3 << endl;
            return;
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cout << fixed << showpoint << setprecision(15);
    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}