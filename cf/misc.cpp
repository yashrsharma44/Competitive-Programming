#include <bits/stdc++.h>
#define int long long
using namespace std;

class Tracker {
   public:
    unordered_map<string, set<int>> mapper;

    Tracker() {
    }

    string allocate(string s) {
        if (mapper.count(s) == 0) {
            int i = 1;
            while (i <= 1000)
                mapper[s].insert(i);
        }
        int val = *mapper[s].begin();
        mapper[s].erase(val);
        return s + to_string(val);
    }

    void deallocate(string s) {
        string host = "", port = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z')
                host += ch;
            else
                port += ch;
        }
        mapper[host].insert(stoll(port));
    }
};

vector<string> split(string s) {
    vector<string> ans;
    string l = "";
    for (auto el : s) {
        if (el == ' ') {
            ans.push_back(l);
            l = "";
        } else {
            l += el;
        }
    }

    ans.push_back(l);
    return ans;
}

int32_t main() {
    Tracker tracker;

    vector<string> ans = {"A apibox", "A apibox", "D apibox1", "A apibox", "A sitebox"};
    for (auto e : ans) {
        vector<string> el = split(e);
        if (el[0] == "A") {
            cout << tracker.allocate(el[1]) << endl;
            ;
        } else {
            tracker.deallocate(el[1]);
        }
    }
}