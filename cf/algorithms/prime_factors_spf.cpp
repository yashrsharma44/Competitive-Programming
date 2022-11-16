// Prime factors of a number
// Using SPF
// TC: O(QlogN + NloglogN)
#include <bits/stdc++.h>
using namespace std;

#define n 1e5 + 100
int spf[(int)n];

void sieve() {
    // the spf of 1 is 1
    spf[1] = 1;

    // make the spf of all number to be itself initially
    for (int i = 2; i <= n; i++) spf[i] = i;

    // make all occurences of even num as 2
    for (int i = 2; i <= n; i += 2) spf[i] = 2;

    // mark the spf
    for (int i = 3; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i + i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

// calculate the prime factors of a number
vector<int> primeFactors(int val) {
    vector<int> ans;
    while (val > 1) {
        ans.push_back(spf[val]);
        val /= spf[val];
    }
    return ans;
}

int main() {
    sieve();
    auto ans = primeFactors(12246);
    for (auto el : ans) cout << el << " ";
    cout << endl;
}
