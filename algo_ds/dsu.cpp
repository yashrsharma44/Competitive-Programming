class DSU {
   public:
    vector<int> par, rnk;
    int N;

    DSU(int n) {
        N = n;
        par = vector<int>(N, -1);
        for (int i = 0; i < N; i++) {
            par[i] = i;
        }
        rnk = vector<int>(N, 0);
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
        if (rnk[xr] < rnk[yr]) {
            swap(xr, yr);
        }
        rnk[xr] += rnk[yr];
        par[yr] = xr;
        return true;
    }

    int size(int x) {
        return rnk[find(x)];
    }
};