#include <bits/stdc++.h>
using namespace std;
#define ll long long

class TrieNode {
   public:
    bool end;
    vector<TrieNode *> children;

    TrieNode() {
        end = false;
        children = vector<TrieNode *>(26, NULL);
    }
};

class Trie {
   public:
    TrieNode *root;

    Trie(vector<string> words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            addWord(words[i]);
        }
    }

    void addWord(string &word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->children[index] == NULL) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->end = true;
    }
};

int solve(vector<string> A, string B, int N) {
    set<string> ans;
    Trie *trie = new Trie(A);

    function<void(int, int)> dfs = [&](int r, int c) {
        if (res.size() > B.size()) return;
        if (res == B) {
            ans.insert(has);
            return;
        }

        if (r < 0 || r >= A.size() || c < 0 || c >= A[0].size()) {
            return;
        }

        int dr[4] = {0, -1, 0, 1};
        int dc[4] = {1, 0, -1, 0};

        char ch = A[r][c];
        A[r][c] = '#';
        for (int k = 0; k < 4; k++) {
            int rr = dr[k] + r;
            int cc = dc[k] + c;

            dfs(rr, cc);
        }
        A[r][c] = ch;
    };

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == B[0]) {
                // cout << i << "|" << j << endl;
                dfs(i, j);
            }
        }
    }

    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
    return ans.size();

    // function<void(TrieNode *, int, int, string)> dfs = [&](TrieNode *node, int i, int j, string res) {
    //     if (node->end) {
    //         ans++;
    //         node->end = false;
    //     }

    //     if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size()) return;
    //     char tmp = A[i][j];

    //     bool isPres = false;
    //     if (node->children[tmp - 'a'] == NULL) return;

    //     A[i][j] = '#';
    //     int dr[4] = {0, -1, 0, 1};
    //     int dc[4] = {1, 0, -1, 0};

    //     for (int k = 0; k < 4; k++) {
    //         int rr = dr[k] + i;
    //         int cc = dc[k] + j;

    //         dfs(node->children[tmp - 'a'], rr, cc, res + tmp);
    //     }
    // };

    // for (int i = 0; i < A.size(); i++) {
    //     for (int j = 0; j < A[0].size(); j++) {
    //         dfs(trie->root, i, j, "");
    //     }
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto ans = solve({"keener", "saloon", "paddle", "needle", "create", "handle"}, "needle", 6);
    cout << ans << endl;

    return 0;
}
