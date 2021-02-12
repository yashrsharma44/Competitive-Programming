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
        if(abs(elems[i] - elems[i+1]) != 0 && abs(elems[i] - elems[i+1]) % d != 0){
            cout<<-1<<endl;
            return;
        }
    }
    int tot = n*m;
    int cnt = INT_MAX;

    vector<int> post(tot, 0);
    for(int i=tot-1;i>0;i--){
        post[i-1] += post[i] + elems[i];
    }

    // 2  4  6  8
    // a1 a2 a3 a4
    // choose a3 - 
    // a3 - a1 + a3 - a2 + a3 - a3 + a4 - a3
    int ans = INT_MAX;
    int pre = 0;
    for(int i=0;i<tot;i++){
        pre += elems[i];
        // ((i+1) * a[i] - pre) + (post[i] - (tot - i) * a[i])
        int val1 = ((i+1) * elems[i]) - pre;
        int val2 = post[i] - (tot - i - 1) * elems[i];
        ans = min(ans, (val1 + val2) / d);
        // cout<<i<<" "<<val1<<" "<<val2<<" "<<ans<<endl;
    }    

    cout<<ans<<endl;
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
