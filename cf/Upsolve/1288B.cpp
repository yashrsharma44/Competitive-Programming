#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll getLength(ll num){

	ll sz = 0;
	while(num != 0){
		sz++;
		num /= 10;
	}

	return sz;
}

void solve(){

	ll A,B;
	cin>>A>>B;

	ll ans = A * (getLength(B + 1) - 1);
	cout<<ans<<endl;
	
}

int main(){

	ll t;
	cin>>t;
	while(t--){
		solve();
	}

}