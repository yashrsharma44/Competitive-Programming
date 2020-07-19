#include <bits/stdc++.h>
#define MOD 998244353
#define int long long 

using namespace std;

class DSU {
public:
    vector<int> par;
    vector<int> rnk;
    DSU(int n){
        par = vector<int>(n+1, -1);
        for(int i=0;i<=n;i++){
            par[i] = i;
        }
        rnk = vector<int>(n+1, 0);
    }
    
    int find(int x){
        
        if(par[x] != x){
            par[x] = find(par[x]); 
        }
        return par[x];
    }
    
    bool Union(int x, int y){
            
        int xr = find(x), yr = find(y);
        if(xr == yr){
            return false;
        }
        if(rnk[xr] < rnk[yr]){
            swap(xr, yr);
        }
        if(rnk[xr] == rnk[yr]){
            rnk[xr]+=1;
        }
        par[yr] = xr;
        return true;
    }    
};

void solve(){

	int n,m;
	cin>>n>>m;

	DSU dsu(n);
	bool isCycle = false;
	vector<vector<int> >unused;
	for(int i=0;i<m;i++){
		int t,x,y;
		cin>>t>>x>>y;
		if(t == 0){
			vector<int> v;
			v.push_back(x);
			v.push_back(y);
			unused.push_back(v);
		} else {
			bool add = dsu.Union(x,y);

			if(add == false){
				isCycle = true;
			}
		}
	}
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
