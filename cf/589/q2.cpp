#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll fast_pow(ll num, ll pw){

	ll ans = 1;
	for(ll i=1;i<=pw;i++){

		ans = (((ans * num) % MOD) + MOD) % MOD;
	}

	return ((ans % MOD) + MOD) % MOD;
}

void solve(){

	ll h,w;
	cin>>h>>w;

	vector< vector<ll> > table(h+1, vector<ll>(w+1, 0));
	vector<ll> r;
	vector<ll> c;

	ll hh = h;
	while(hh--){
		ll vl;
		cin>>vl;
		r.push_back(vl);
	}

	ll ww = w;
	while(ww--){
		ll vl;
		cin>>vl;
		c.push_back(vl);
	}

	// Fill up rows
	for(ll i=0;i<r.size();i++){

		for(ll j=1;j<=r[i];j++){

			table[i+1][j] = 1;

		}

	}

	// Fill up columns
	for(ll i=0;i<c.size();i++){

		for(ll j=1;j<=c[i];j++){

			table[j][i+1] = 1;

		}
	}
	// for(vector<ll> p : table){
	// 	for(ll el : p){
	// 		cout<<el<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// Check if invalid then return 0
	// Count rows
	for(ll i=0;i<h;i++){

		ll cnt = 0;
		for(ll j=0;j<w;j++){

			if(table[i+1][j+1] == 1){
				cnt += 1;
			} else {
				break;
			}

		}
		// cout<<"C"<<cnt<<" "<<r[i]<<endl;
		if(cnt != r[i]){
			cout<<0<<endl;
			return;
		}
	}

	//  Count columns
	for(ll i=0;i<w;i++){

		ll cnt = 0;
		for(ll j=0;j<h;j++){

			if(table[j+1][i+1] == 1){
				cnt++;
			} else {
				break;
			}
		}

		if(cnt != c[i]){
			cout<<0<<endl;
			return;
		}
	}





	// 1st row and col should not be selected
	// Check if a cell's index == cum_sum of that row + 1

	ll count = 0;

	for(ll i=2;i<=h;i++){

		for(ll j=2;j<=w;j++){

			if(table[i][j] == 0){

				if(r[i-1] + 1 != j && c[j-1] + 1 != i){
					count++;
				}
			}

		}
	}

	// cout<<count<<endl;
	// if(count == 0){
	// 	cout<<0<<endl;
	// 	return;
	// }
	cout<<fast_pow(2, count)<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}