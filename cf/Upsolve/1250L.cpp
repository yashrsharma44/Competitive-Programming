#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll a,b,c;
	cin>>a>>b>>c;

	if(b < min(a,c)){
		ll ans = min(max(a,c), (max(a,c) + b) / 2);
		cout<<ans<<endl;
		return;
	} 

	ll v = a+b+c;
	if(v%3 == 0){
		cout<<(a+b+c) / 3<<endl;
	} else {
		cout<<(v/3)+1<<endl;
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}