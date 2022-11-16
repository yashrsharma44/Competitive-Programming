#include <bits/stdc++.h>
using namespace std;

class DSU {
   public:
    vector<int> par, sz;
    int N;

    DSU(int N) {
        sz = vector<int>(N, 1);
        par = vector<int>(N, -1);

        for (int i = 0; i < N; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool Union(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;

        if (sz[xr] < sz[yr]) swap(xr, yr);
        par[yr] = xr;
        sz[xr] += sz[yr];
        return true;
    }

    int size(int x) {
        return sz.size(find(x));
    }
};
