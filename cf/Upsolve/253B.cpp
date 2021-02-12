#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

    int n; cin>>n;
    vector<int> a;
    int nn = n;
    while(nn--){
        int u; cin>>u;
        a.push_back(u);
    }

    vector<int> count(5005, 0);
    for(auto el : a){
        count[el] ++;
    }

    int ans = INT_MAX;
    for(int i=1;i<=5000;i++){
        int val = i;
        int cnt = 0;
        for(int j=1;j<=5000;j++){
            if(j < val || j > 2*val){
                cnt+=count[j];
            }
        }
        ans = min(ans, cnt);
    }

    cout<<ans<<endl;
   
}

int32_t main(){

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);


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