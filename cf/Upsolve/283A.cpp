#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 3) {
            // remove last element
            sum -= arr.back();
            arr.pop_back();
            cout << (sum / arr.size()) << endl;
        } else if (t == 2) {
            
        }
    }
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