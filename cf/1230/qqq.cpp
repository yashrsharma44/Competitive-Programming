#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n <= 6 || m == 0)
    {
        cout << m << endl;
        return 0;
    }
    int sum = 0;
    for (int i = 1; i < 7; i++)
    {
        for (int j = i + 1; j <= 7; j++)
        {
            vector<bool> vis(8, false);
            int cnt = 0, u = 0, v = 0;
            for (; u < adj[i].size(); u++)
                vis[adj[i][u]] = true;
            for (; v < adj[j].size(); v++)
                if (!vis[adj[j][v]])
                    vis[adj[j][v]] = true;
            for (int k = 1; k <= 7; k++)
                if (vis[k])
                    cnt++;
            cout << u << ' ' << v << ' ' << cnt << endl;
            sum = max(sum, m - u - v + cnt);
        }
    }
    cout << sum << endl;
}