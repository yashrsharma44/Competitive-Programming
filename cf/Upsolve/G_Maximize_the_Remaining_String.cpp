#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    vector<char> a;
    
    map<char, int> cnt;
    for (auto ch : s) cnt[ch]++;

    for(auto ch : s){
        if(cnt[ch] > 1) a.push_back('0');
        else a.push_back(ch);
    }

    

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