#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());
    multiset<int> ms;
    int sum = 0;
    for (auto el : nums) {
        ms.insert(el);
        sum += el;
    }
    if (ms.count(0) == 0) {
        cout << -1 << endl;
        return;
    }

    if (sum % 3 == 1) {
        // remove 1 element with a%3==1
        bool isPos = false;
        for (auto el : nums) {
            if (el % 3 == 1) {
                ms.erase(ms.find(el));
                isPos = true;
                break;
            }
        }
        // or remove 2 element with a%3==2 and b%3==2
        int cnt = 0;
        if (!isPos) {
            for (auto el : nums) {
                if (cnt < 2 && el % 3 == 2) {
                    ms.erase(ms.find(el));
                    cnt++;
                }
            }
        }
        if (cnt == 2) isPos = true;

        if (!isPos) {
            cout << -1 << endl;
            return;
        }

    } else if (sum % 3 == 2) {
        bool isPos = false;
        // remove 1 element with a%3==2
        for (auto el : nums) {
            if (el % 3 == 2) {
                ms.erase(ms.find(el));
                isPos = true;
                break;
            }
        }
        // or remove 2 element with a%3==1 and b%3==1
        int cnt = 0;
        if (!isPos) {
            for (auto el : nums) {
                if (cnt < 2 && el % 3 == 1) {
                    ms.erase(ms.find(el));
                    cnt++;
                }
            }
        }

        if (cnt == 2) isPos = true;

        if (!isPos) {
            cout << -1 << endl;
            return;
        }
    }

    if (ms.count(0) == ms.size()) {
        cout << 0 << endl;
        return;
    }

    for (auto it = ms.rbegin(); it != ms.rend(); it++) {
        cout << *it;
    }
    cout << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
}