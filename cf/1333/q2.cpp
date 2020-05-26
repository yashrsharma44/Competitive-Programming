#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a, b;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		b.push_back(vl);
	}

	vector<ll> c(n,0);
	for(ll i=0;i<n;i++){
		c[i] = b[i] - a[i];
	}

	vector< vector<ll> > dp(n, vector<ll>(3, 0));

	if(c[0] == 0){
		if(a[0] == -1){
			dp[0][0] = 1;
		}
		if(a[0] == 0){
			dp[0][1] = 1;
		}

		if(a[0] == 1){
			dp[0][2] = 1;
		}
	}

	for(int i=1;i<n;i++){
		
		if(a[i] == -1){
			dp[i][0] = 1;
		} else if(a[i] == 0){
			dp[i][1] = 1;
		} else if(a[i] == 1){
			dp[i][2] = 1;
		}
		
		dp[i][0] += dp[i-1][0];
		dp[i][1] += dp[i-1][1];
		dp[i][2] += dp[i-1][2];
	}

	bool isPos = true;
	if(c[0] != 0){
		isPos = false;
	}
	for(ll i=1;i<n;i++){

		if(c[i] != 0){
			if(c[i] < 0){
				if(dp[i-1][0] == 0){
					isPos = false;
					break;
				}
			} else if(c[i] > 0){
				if(dp[i-1][2] == 0){
					isPos = false;
					break;
				}
			}
		}
	}

	if(isPos){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}	

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}