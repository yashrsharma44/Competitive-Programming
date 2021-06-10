#include <bits/stdc++.h>
#define int long long
using namespace std;

// --------------- SIEVE -----------------
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

// ---------------------------------------
// -------------PBDS----------------------

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

// ----------------------------------------
// --------------SEGTREE WITH MIN-----------

const int maxn = 1 << 18;
pair<int, int> tree[maxn * 2];

void build(const vector<int> &a, int n) {
    for (int i = 0; i < n; i++) tree[maxn + i] = {a[i], i};
    for (int i = maxn - 1; i > 0; i--)
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

int get(int l, int r) {
    pair<int, int> ans{-1, -1};
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, tree[l++]);
        if (r & 1) ans = max(ans, tree[--r]);
    }
    return ans.second;
}