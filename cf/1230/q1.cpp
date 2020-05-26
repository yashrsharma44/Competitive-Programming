#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	vector<ll> a;
	ll n = 4;
	while(n--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	sort(a.begin(), a.end());

	if((a[0] + a[3] == a[1] + a[2]) || (a[0] + a[2] == a[1] + a[3]) || (a[0] + a[1] == a[2] + a[3]) || (a[0]+a[1]+a[2] == a[3])){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}

}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}