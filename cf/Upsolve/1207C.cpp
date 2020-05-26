
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,a,b;
	cin>>n>>a>>b;

	string s;
	cin>>s;

	// ll n = s.length();
	vector < vector<ll> >dp(n+1, vector<ll>(2, 1e18));

	dp[0][0] = b;

	for(ll i=0;i<n;i++){

		if(s[i] == '0'){

			dp[i+1][0] = min(dp[i+1][0], dp[i][0] + (a+b));
			dp[i+1][1] = min(dp[i+1][1], dp[i][0] + 2*(a+b));

			dp[i+1][1] = min(dp[i+1][1], dp[i][1] + (a + (2*b)));
			dp[i+1][0] = min(dp[i+1][0], dp[i][1] + (2*a)+b);

		} else {
		
			dp[i+1][1] = min(dp[i+1][1], dp[i][1] + (a+b+b));
		
		}

	}

	cout<<dp[n][0]<<endl;

}

int main(){

	ll t;
	cin>>t;
	// t=1;
	while(t--){
		solve();
	}
}