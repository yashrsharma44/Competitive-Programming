#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;

	ll ans1 = (n / k);
	ll rem = n - (ans1 * k);

	ll ans2 = min((k / 2), rem);
	cout<<((ans1 * k) + ans2)<<endl;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}