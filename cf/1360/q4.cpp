#include <bits/stdc++.h>
#define ll int

using namespace std;


void solve(){

	ll n;
	cin>>n;

	vector < vector<ll> > grid(n, vector<ll>(n, 0));
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			char c;
			cin>>c;
			if(c == '1'){
				grid[i][j] = 1;
			}
		}
	}



	vector < vector<ll> > rrow(n, vector<ll>(n, 0));
	for(ll i=0;i<n;i++){

		rrow[i][n-1] = grid[i][n-1] == 1 ? 1 : 0;
		for(ll j=n-2;j>=0;j--){
			rrow[i][j] = (rrow[i][j+1] == 1 && grid[i][j] == 1) || (grid[i][j] == 1 && grid[i][j+1] == 1) ? 1 : 0;
		}

	}

	vector < vector<ll> > ccol(n, vector<ll>(n, 0));
	for(ll j=0;j<n;j++){

		ccol[n-1][j] = grid[n-1][j] == 1 ? 1 : 0;
		for(ll i=n-2;i>=0;i--){
			ccol[i][j] = (ccol[i+1][j] == 1 && grid[i][j] == 1)  || (grid[i][j] == 1 && grid[i+1][j] == 1) ? 1 : 0;
		}
	}

	if(n == 2){
		bool isPos = true;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				if(grid[i][j] == 1){
					if(rrow[i][j] == 0 && ccol[i][j] == 0){
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
		return;
	}

	bool isPos = true;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(grid[i][j] == 1){
				if(rrow[i][j] == 0 && ccol[i][j] == 0){
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
	// t=1;

	while(t--){
		solve();
	}

}