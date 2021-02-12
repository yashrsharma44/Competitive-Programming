#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

    int n; cin>>n;
    int val = sqrt(n);

    for(int i=1;i<=val;i++){
        int v2 = sqrt((n - (i*(i+1) / 2)) * 2);
        if(v2!=0 && v2*(v2+1) + i*(i+1) == 2 * n){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
