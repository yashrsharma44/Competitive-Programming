#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
		
	ll n,m;
	cin>>n>>m;

	vector<ll> cum(n,0), arr(n,0);
	vector<ll> a;

	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;

		a.push_back(vl);
	}

	sort(a.begin(), a.end());

	cum[0] = a[0];
	for(ll i=1;i<n;i++){
		cum[i] = cum[i-1] + a[i];
	}

	for(ll i=0;i<n;i++){

		if(i < m){
			arr[i] = cum[i];
		} else {
			arr[i] = arr[i-m] + cum[i];
		}
	}

	for(ll el:arr){
		cout<<el<<" ";
	}
	cout<<endl;


}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}

}