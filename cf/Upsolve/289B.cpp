#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

    int n,m,d; cin>>n>>m>>d;
    int sum = 0;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    vector<int> elems;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            elems.push_back(grid[i][j]);
            sum += elems.back();
        }
    }

    sort(elems.begin(), elems.end());
    for(int i=0;i<(n*m)-1;i++){
        if(abs(elems[i] - elems[i+1]) % d != 0){
            cout<<-1<<endl;
            return;
        }
    }
    int tot = n*m;
    int cnt = INT_MAX;
    
    // a3 - a1 + a3 - a2 + a3 - a4
    //    4 + 2 + 2

    for(int i=0;i<tot;i++){
        // a1 - a2 + a1 - a3 ...
        int val = ((tot - 1) * elems[i]) - (sum - elems[i]);
        val *= 2;
        if(val > 0)
            cout<<elems[i]<<"-"<<val / d<<endl;
            cnt = min(cnt, val / d);
    }    

    cout<<cnt<<endl;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
