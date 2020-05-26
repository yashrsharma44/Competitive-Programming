#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	// Using DP to solve this problem.
	// We have 2 choices to make for each prefix
	// We choose it
	// We don't choose it

	// We can choose it if we are ensured that removing the i-1
	// element can maintain the increasing array nature.
	// Else it doesn't make any sense to remove the prev element

	// If we remove the prev element, then we have to choose the
	// max len of all increasing subarray at this point which has
	// not removed any element, because we can remove atmost one element

	// If we dont choose the prev element, we can choose the prev count
	// if the increasing nature is maintained, else we have to restart the count

	ll n;
	cin>>n;

	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	vector < vector <ll> > dp(n+1, vector<ll>(2, -1));

	dp[0][1] = 1;
	dp[0][0] = 1;

	dp[1][1] = (a[1] > a[0]) ? 2 : 1;
	dp[1][0] = (a[1] > a[0]) ? 2 : 1;


	for(ll i=2;i<n;i++){

		if(a[i] > a[i-2]){

			dp[i][1] = max(dp[i][1], dp[i-2][0] + 1);

		} else if(a[i] > a[i-1]){

			dp[i][1] = max(dp[i][1], 1 + dp[i-1][1]);
			dp[i][0] = max(dp[i][0], 1 + dp[i-1][0]);
		
		} else {

			dp[i][1] = 1;
			dp[i][0] = 1;
		
		}

	}

	cout<<max(dp[n-1][0], dp[n-1][1])<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}