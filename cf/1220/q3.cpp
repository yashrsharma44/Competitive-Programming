#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	string s;
	cin>>s;

	vector<ll> dp(s.length(),0);
	ll n = s.length();
	dp[0] = 0;

	for(ll i=1;i<n;i++){

		if(s[i-1] < s[i]){
			dp[i] += dp[i-1] + 1;
		} else {
			dp[i] = 0;
		}
	}	
	cout<<"Mike"<<endl;

	for(ll i=1;i<n;i++){

		ll el = dp[i];

		if(el == 0){
			cout<<"Ann"<<endl;
		} else {
			cout<<"Mike"<<endl;
		}

	}

}

int main(){
	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}