#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	vector < vector<ll> > dp(n+1, vector<ll>(31, 0));

	for(ll i=1;i<=n;i++){
		for(ll j=max(a[i-1],0ll);j<=30;j++){
			dp[i][j] = max(dp[i-1][j] + a[i-1], 0ll);	
		}
	}

	ll best = INT_MIN;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=30;j++){
			best = max(best, dp[i][j] - j);
		}
	}


	// int i,j,N=n;
	// cout<<"j:     ";
	// for(j=0;j<=30;j++){
	//   printf("%3d ", j);
	// } 
	// cout<<endl;
	// for(i=0;i<=N;i++){
	// printf("%2d-----",i);
	// for(j=0;j<=30;j++){
	//   printf("%3d ", (int)dp[i][j]);
	// }
	// cout<<endl;
	// }
	// cout<<endl;


	cout<<best<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}