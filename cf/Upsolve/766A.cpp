#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	string s,t;
	cin>>s>>t;

	if(s == t){
		cout<<-1<<endl;
		return;
	}
	cout<<max(s.length(), t.length())<<endl;
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
