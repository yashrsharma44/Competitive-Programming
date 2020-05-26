#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n,q;
	cin>>n>>q;

	ll dc[3] = {-1, 0, 1};
	// ll dc[3] = {}

	vector< vector<ll> > table(3, vector<ll>(n+1, 0));

	ll qq =q;
	ll lavaCount = 0;
	while(qq--){

		ll u,v;
		cin>>u>>v;

		table[u][v] = 1 - table[u][v];


		if(table[u][v] == 1){
			
			// Check if at the row 1
			if(u == 1){
				for(ll k=0;k<3;k++){

					if((v+dc[k] >= 1 && v+dc[k] <= n) && table[u+1][v + dc[k]] == 1){
						lavaCount += 1;
					}
				}
			} else {
				for(ll k=0;k<3;k++){

					if((v+dc[k] >= 1 && v+dc[k] <= n) && table[u-1][v + dc[k]] == 1){
						lavaCount += 1;
					}
				}
			}

		} else {
			if(u == 1){
				for(ll k=0;k<3;k++){

					if((v+dc[k] >= 1 && v+dc[k] <= n) && table[u+1][v + dc[k]] == 1){
						lavaCount += -1;
					}
				}
			} else {
				for(ll k=0;k<3;k++){

					if((v+dc[k] >= 1 && v+dc[k] <= n) && table[u-1][v + dc[k]] == 1){
						lavaCount += -1;
					}
				}
			}
		}

		if(lavaCount != 0){
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}

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