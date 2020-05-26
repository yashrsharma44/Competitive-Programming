#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	
	string s;
	cin>>s;

	vector<ll> d;
	for(int i=0;i<n;i++){
		d.push_back(s[i] - '0');
	}

	// vector<ll> color(n, 0);
	for(int x=1;x<=9;x++){
		vector<ll> color(n,0);
		for(ll i=0;i<n;i++){
			if(d[i] < x){
				color[i] = 1;
			} else if(d[i] > x){
				color[i] = 2;
			}
		}

		ll mx = -1;
		for(ll i=0;i<n;i++){
			mx = max(mx, d[i]);
			if(color[i] == 0){
				if(mx == x){
					color[i] = 2;
				} else {
					color[i] = 1;
				}
			}
		}

		// Check if valid
		bool isNonDec = true;

		for(ll i=0;i<n;i++){
			if(color[i] == 0){
				isNonDec = false;
				break;
			}
		}

		
		ll prev = -1;
		for(ll i=0;i<n;i++){
			if(color[i] == 1 && prev == -1){
				prev = d[i];
			} else if(color[i] == 1 && prev != -1){
				if(d[i] < prev){
					isNonDec = false;
					break;
				} 
				prev = d[i];
			}
		}

		prev = -1;
		for(ll i=0;i<n;i++){
			if(color[i] == 2 && prev == -1){
				prev = d[i];
			} else if(color[i] == 2 && prev != -1){
				if(d[i] < prev){
					isNonDec = false;
					break;
				}
				prev = d[i];
			}
		}

		if(isNonDec){
			for(ll i=0;i<n;i++){
				cout<<color[i];
			}
			cout<<endl;
			return;
			// break;
		}

	}

	cout<<"-"<<endl;




}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}