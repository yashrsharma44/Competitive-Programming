#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n;
	cin>>n;

	set<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;

		a.insert(vl);
	}

	cout<<a.size()<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}