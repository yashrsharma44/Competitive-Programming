#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}
	ll one_idx =  -1;
	for(ll i=0;i<n;i++){
		if(a[i]==1){
			one_idx = i;
			break;
		}
	}


	ll one_c = 0;
	for(ll i=0;i<n;i++){
		if(a[i] == 1){
			one_c++;
		}
	}

	if(one_c == 1){
		cout<<-1<<endl;
		return;
	}

	if(one_idx == -1){
		cout<<0<<endl;
		return;
	}

	ll ans = 0;
	for(ll i=0;i<n;i++){
		if(i!=one_idx && a[i] == 1){
			ans += min((i - one_idx), n - (i - one_idx));
		}
	}

	cout<<ans<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
