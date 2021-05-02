#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;
int c1 = 0, c2 = 0;
void solve() {
    auto getInput = [&](int l, int r) {
        cout << "? " << l << " " << r << endl;
        fflush(stdout);
        string s;
        cin >> s;
        c1++;
        return s == "y";
    };

    auto getInput2 = [&](int l, int r) {
        cout << "? " << l << " " << r << endl;
        fflush(stdout);
        string s;
        cin >> s;
        c2++;
        return s == "x";
    };

    int l = 0, r = 1;
    while (getInput(l, r)) {
        l = r;
        r <<= 1;
    }

    //  a lies in [l, r], or in other words, l <= a <= r
    // such that l * 2 == r

    int left = l + 1, right = r + 1;

    // THIS BSEARCH FOR SOME REASON DOES NOT WORK WITHIN LIMITS

    // // getInput2(l, m) returns if l >= m, we want first True
    // while (left < right) {
    //     int m = (left + right) >> 1;
    //     if (!getInput(l, m))
    //         right = m;
    //     else
    //         left = m + 1;
    // }
    // cout << right << endl;

    // LETS TRY (r - l > 1) binary search
    // FOR SOME FUCKING REASON, THIS CONVERGES MUCH MUCH FASTER :(
    left = l;
    while (right - left > 1) {
        int m = (left + right) >> 1;
        if (getInput2(l, m))
            right = m;
        else
            left = m;
    }
    // cout << c1 << "===" << c2 << endl;
    cout << "! " << left + 1 << endl;
    fflush(stdout);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto getTest = [&]() {
        string s;
        cin >> s;
        return s == "start";
    };

    while (getTest()) {
        solve();
    }
}