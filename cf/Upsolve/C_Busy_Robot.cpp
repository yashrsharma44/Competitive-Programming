#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> entry;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        entry.push_back({u, v});
    }

    map<int, int> pos;
    pos[0] = 0;

    map<int, int> dx;
    dx[0] = 0;

    int i = 0;
    int lastPos = 0;
    int lastTime = 0;

    while (i < n) {
        auto timestamp = entry[i];

        int startTime = timestamp[0];
        int diff = abs(timestamp[1] - lastPos);

        int curDir = timestamp[1] >= lastPos ? 1 : -1;
        int endTime = startTime + diff;

        dx[endTime] = 0;

        if (entry[i][0] >= endTime) {
            i++;
        } else {
            while (i < n && entry[i][0] < endTime) {
                dx[entry[i][0]] = curDir;
                int curPos = lastPos + curDir * (entry[i][0] - startTime);
                pos[entry[i][0]] = curPos;
                i++;
            }
        }
        lastPos = lastPos + curDir * diff;
        pos[endTime] = lastPos;
    }

    // cout << "DBG: \n";
    // for (auto el : pos) cout << el.first << " " << el.second << endl;
    int ans = 0;
    for (int i = 0; i < entry.size() - 1; i++) {
        int minx = min(pos[entry[i + 1][0]], pos[entry[i][0]]);
        int maxx = max(pos[entry[i + 1][0]], pos[entry[i][0]]);
        if (entry[i][1] >= minx && entry[i][1] <= maxx) ans++;
    }
    int lastTimeStamp = entry.back()[0];
    lastPos = entry.back()[1];

    if (dx[lastTimeStamp] == 0) {
        if (lastPos == pos[lastTimeStamp]) ans++;
    } else {
        int startTime = lastTimeStamp;
        int endTime = pos.rbegin()->first;

        int minx = min(pos[startTime], pos[endTime]);
        int maxx = max(pos[startTime], pos[endTime]);

        if (lastPos >= minx && lastPos <= maxx) ans++;
    }

    cout << ans << endl;
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