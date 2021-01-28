#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n; cin>>n;
	string b; cin>>b;

	int prev = 1 + b[0] - '0';
	cout<<1;
	for(int i=1;i<n;i++){
		if(prev != (b[i] - '0') + 1){
			cout<<1;
			prev = (b[i] - '0') + 1;
		} else {
			cout<<0;
			prev = b[i] - '0';
		}
	}
	cout<<endl;

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
