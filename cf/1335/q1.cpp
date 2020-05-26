#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	if(n <= 2){
		cout<<0<<endl;
		return;
	}

	if(n == 3){
		cout<<1<<endl;
		return;
	}

	if(n % 2 == 1){
		cout<<n/2<<endl;
	} else {
		n = n - 1;
		cout<<n/2<<endl;
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}