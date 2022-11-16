#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> solve(vector<int> s, vector<int> d, vector<int> p) {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto ans = solve({0, 10, 20, 30, 40, 50}, {10, 10, 10, 10, 10, 10}, {0, 3, 0, 3, 0, 3});
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}
