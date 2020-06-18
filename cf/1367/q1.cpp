#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	string s;
	cin>>s;

	string ans = "";
	for(int i=0;i<s.length();i+=2){
		ans += s[i];
	}

	ans+=s[s.length()-1];
	cout<<ans<<endl;

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
