#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> c1;
	vector<ll> c2;
	vector<ll> c3;

	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		c1.push_back(vl);
	}

	nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		c2.push_back(vl);
	}

	nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		c3.push_back(vl);
	}

	vector<ll> edgeCount(n+1, 0);
	
	nn = n-1;
	for(ll i=0;i<n-1;i++){
		ll u,v;
		cin>>u>>v;
		edgeCount[u] += 1;
		edgeCount[v] += 1;
	}	
	// cout<<"O"<<endl;

	bool isPossible = true;
	for(ll el : edgeCount){

		if(el > 2){
			isPossible = false;
			break;
		}
	}

	if(isPossible){

		// vector < pair <ll, vector<ll> > dp[n+1][3]();
		ll dp[n+1][3];

		ll ans1[n];
		ll ans2[n];
		ll ans3[n];

		dp[1][0] = c1[0];
		dp[1][1] = c2[0];
		dp[1][2] = c3[0];

		ans1[0] = 1;
		ans2[0] = 2;
		ans3[0] = 3;

		for(ll i=2;i<=n;i++){

			// Choose 1

			if(dp[i-1][1] < dp[i-1][2]){

				ans1[i] = 2;

			} else {

				ans1[i] = 3;

			}

			dp[i][0] = c1[i] + min(dp[i-1][1], dp[i-1][2]);



			if(dp[i-1][0] < dp[i-1][2]){

				ans1[i] = 1;

			} else {

				ans1[i] = 3;

			}
			// Choose 2
			dp[i][1] = c2[i] + min(dp[i-1][0], dp[i-1][2]);


			if(dp[i-1][0] < dp[i-1][1]){

				ans1[i] = 1;

			} else {

				ans1[i] = 2;

			}

			// Choose 3
			dp[i][2] = c3[i] + min(dp[i-1][0], dp[i-1][1]);

		}
		


		cout<<min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]))<<endl;

		if(dp[n-1][0] <= dp[n-1][1]){

			if(dp[n-1][0] <= dp[n-1][2]){

				for(ll el : ans1){
					cout<<el<<" ";
				}
				cout<<endl;

			} 
		}

		else if(dp[n-1][1] <= dp[n-1][2]){

			if(dp[n-1][1] <= dp[n-1][0]){

				for(ll el : ans2){
					cout<<el<<" ";
				}
				cout<<endl;

			} 
		} else {
			for(ll el : ans3){
				cout<<el<<" ";
			}
			cout<<endl;
		}


	} else {
		cout<<-1<<endl;
	}


}

int main(){

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}