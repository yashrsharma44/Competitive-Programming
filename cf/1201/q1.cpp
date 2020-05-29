#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	vector<string> a;
	ll nn = n;
	while(nn--){
		string s;
		cin>>s;
		a.push_back(s);
	}

	vector<ll> mar;
	ll mm = m;
	while(mm--){
		ll vl;
		cin>>vl;
		mar.push_back(vl);
	}

	ll points = 0;
	for(ll j=0;j<m;j++){

		map<ll,ll> mp;
		for(ll i=0;i<n;i++){
			mp[a[i][j] - 'A'] += 1;
		}

		ll mx = -1;
		ll mxa = -1;
		for(auto el : mp){
			if(mx < el.second){
				mx = el.second;
				mxa = el.first;
			}
		}
		points+=(mx * mar[j]);
	}

	cout<<points<<endl;
		
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
