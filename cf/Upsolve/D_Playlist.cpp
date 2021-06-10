#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

class DLL {
   public:
    DLL *prev, *next;
    int val;
    int idx;

    DLL(int val, int index) {
        this->val = val;
        this->idx = index;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        if (a[0] == 1) {
            cout << "1 1" << endl;
            return;
        }
        cout << 0 << endl;
        return;
    }

    DLL *start = new DLL(a[0], 0);

    DLL *it = start;
    for (int i = 1; i < n; i++) {
        DLL *node = new DLL(a[i], i);
        it->next = node;
        node->prev = it;

        it = node;
    }

    it->next = start;
    start->prev = it;

    it = start;

    // here the size of the array >= 2
    queue<vector<DLL *>> process;
    set<DLL *> present;
    DLL *it2 = it;
    do {
        present.insert(it);
        DLL *node1 = it, *node2 = it->next;
        if (__gcd(node1->val, node2->val) == 1) process.push({node1, node2});
        it = node2;
    } while (it2 != it);

    vector<int> ans;

    // process all the available node, and then exit
    while (!process.empty()) {
        auto entry = process.front();
        process.pop();
        DLL *node1 = entry[0], *node2 = entry[1];

        // check if the nodes are not erased
        if (present.count(node1) == 0 || present.count(node2) == 0) continue;
        present.erase(node2);

        // if gcd(a, c) == 1, insert it to process
        DLL *node3 = node2->next;
        if (__gcd(node1->val, node3->val) == 1) process.push({node1, node3});

        // delete the node2
        node1->next = node3;
        node3->prev = node1;
        ans.push_back(node2->idx);
    }

    cout << ans.size() << " ";
    for (auto el : ans) cout << el + 1 << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}