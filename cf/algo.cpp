#include <bits/stdc++.h>
using namespace std;
#define ll long long

char a[1001][1001][4];
ll ans[1001][1001];
ll inf = 1e9;
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;

void bfs(ll i, ll j, ll n, ll m) {
    ll x = 0, p = 0, r = 0;
    if (i - 1 >= 0) {
        r = 0;
        x = 0;
        while (a[i][j][(r) % 4] != a[i - 1][j][(p + 2) % 4]) {
            // r--;
            if (r == -1)
                r = 3;
            x++;
        }
        pq.push({ans[i][j] + x, (i - 1) * m + j});
    }
    if (i + 1 < n) {
        p = 2;
        r = 2;
        x = 0;
        while (a[i][j][(r) % 4] != a[i + 1][j][(p + 2) % 4]) {
            r--;
            if (r == -1)
                r = 3;
            x++;
        }
        pq.push({ans[i][j] + x, (i + 1) * m + j});
    }
    if (j - 1 >= 0) {
        p = 3;
        r = 3;
        x = 0;
        while (a[i][j][r] != a[i][j - 1][(p + 2) % 4]) {
            r--;
            if (r == -1)
                r = 3;
            x++;
        }
        pq.push({ans[i][j] + x, i * m + j - 1});
    }
    if (j + 1 < m) {
        p = 1;
        r = 1;
        x = 0;
        while (a[i][j][r] != a[i][j + 1][(p + 2) % 4]) {
            r--;
            if (r == -1)
                r = 3;
            x++;
        }
        pq.push({ans[i][j] + x, i * m + j + 1});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> a[i][j][k];
            }
        }
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            ans[i][j] = inf;
        }
    }
    pq.push({0, 0});
    while (!pq.empty()) {
        pair<ll, ll> curr = pq.top();
        ll i = curr.second / m;
        ll j = curr.second - (m * i);
        if (ans[i][j] > pq.top().first) {
            ans[i][j] = pq.top().first;
            pq.pop();
            bfs(i, j, n, m);
        } else {
            pq.pop();
        }
    }
    cout << ans[n - 1][m - 1];
    return 0;
}