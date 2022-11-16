#include <bits/stdc++.h>

#define int long long
#define MOD 100000007

using namespace std;

class TrieNode {
   public:
    int value;
    int count;
    TrieNode *children[2];

    TrieNode() {
        count = 0;
        value = 0;
        children[0] = children[1] = NULL;
    }
};

class Trie {
   public:
    int LEVEL;
    TrieNode *root;

    Trie() {
        root = new TrieNode();
        LEVEL = 18;
    }

    void insert(int value) {
        TrieNode *curr = root;
        for (int i = LEVEL; i >= 0; i--) {
            int bit = (value >> i) & 1;
            if (curr->children[bit] == NULL) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
            curr->count += 1;
        }
    }

    int count(int value, int maxx) {
        TrieNode *curr = root;
        int ans = 0;
        for (int i = LEVEL; i >= 0; i--) {
            if (curr == NULL) break;
            int n = (value >> i) & 1;
            int k = (maxx >> i) & 1;

            if (k == 0) {
                curr = curr->children[n];
            } else {
                if (curr->children[n] != NULL) {
                    ans += curr->children[n]->count;
                }
                curr = curr->children[1 ^ n];
            }
        }
        return ans;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // find the number of beautiful subarrays
    // i < j, S[i] ^ S[j] - XOR between i and j
    // such that XOR(S[i...j]) >= k

    // Lets use a trie for storing all possible S[i]
    // and for a given S[j], choose all nos such that S[j] ^ S[i] >= k

    Trie *trie = new Trie();
    int left = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int el = a[i];
        left ^= el;
        ans += i - trie->count(left, k);
        trie->insert(left);
    }

    cout << ans << endl;
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