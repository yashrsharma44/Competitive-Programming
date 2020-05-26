#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	string s;
	cin>>s;

	vector<ll> color(n, -1);

	char prev = s[0];
	color[0] = 0;

	for(ll i=1;i<n;i++){

		if((ll)(s[i] - prev) >= 0){
			color[i] = 0;
			prev = s[i];
		}
	}

	prev = 0;
	for(ll i=1;i<n;i++){
		if(color[i] == -1){
			prev = s[i];
			color[i] = 1;
			break;
		}
	}

	for(ll i=1;i<n;i++){

		if(color[i] == -1){

			if((ll)(s[i] - prev) >= 0){
				color[i] = 1;
				prev = s[i];
			}
		}

	}


	bool isPos = true;
	for(ll i=0;i<n;i++){

		if(color[i] == -1){
			isPos = false;
			break;
		}

	}

	if(isPos){
		cout<<"YES"<<endl;
		for(ll el : color){
			cout<<el;
		}
		cout<<endl;
	} else {
		cout<<"NO"<<endl;
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