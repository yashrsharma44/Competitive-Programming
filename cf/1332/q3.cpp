#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool palin(string s){

	ll p1 = 0, p2 = s.length()-1;

	while(p1 < p2){
		if(s[p1] != s[p2]){
			return false;
		}
		p1++;
		p2--;
	}
	return true;
}

void solve(){

	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;

	vector<map<char,ll> > v((k+1)/2, map<char,ll>());
	for(ll i=0;i<n/k;i++){

		for(ll j=0;j<(k+1)/2;j++){

			ll start_idx = j+(i*k);
			ll end_idx = ((i+1) * k) - j - 1;
			// cout<<j<<":"<<start_idx<<" "<<end_idx<<endl;
			v[j][s[start_idx]]++;
			if(start_idx != end_idx){
				v[j][s[end_idx]]++;
			}
		}

	}

	ll count = 0;
	for(auto el : v){

		ll mx = -1;
		ll xx = 0;
		for(auto p : el){
			mx = max(mx, p.second);
			xx+=p.second;
		}
		ll l = n / k;
		count+=((xx) - mx);
	}

	cout<<count<<endl;
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