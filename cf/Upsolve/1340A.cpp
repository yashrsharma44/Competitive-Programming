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

	for(ll i=1;i<n;i++){

		if(a[i-1] < a[i]){
			if(a[i-1]+1 != a[i]){
				cout<<"No"<<endl;
				return;
			}
		}
	}

	cout<<"Yes"<<endl;
	
}

int main(){

	ll t;
	cin>>t;
	// t = 1;
	while(t--){
		solve();
	}

}