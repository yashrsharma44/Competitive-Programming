#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){


	ll n,m;
	cin>>n>>m;

	if(n == 1){
		cout<<0<<endl;
		return;
	}

	if(n == 2){
		cout<<m<<endl;
		return;
	}

	cout<<(2*m)<<endl;

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
