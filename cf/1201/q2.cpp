#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a;
	ll nn = n;
	ll sum = 0;
	ll mx = -1;
	while(nn--){
		ll vl;
		cin>>vl;
		mx = max(mx, vl);
		sum+=vl;
		a.push_back(vl);
	}

	sum -= mx;
	if((sum + mx) % 2 == 0 && mx <= sum){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	
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
