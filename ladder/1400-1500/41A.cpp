#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	string s,t; cin>>s>>t;
	reverse(s.begin(), s.end());
	if(s!=t){
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
	}

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
