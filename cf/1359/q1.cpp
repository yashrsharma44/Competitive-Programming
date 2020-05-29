#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
		
	ll n,m,k;
	cin>>n>>m>>k;

	ll l = n / k;
	if(l >= m){
		cout<<m<<endl;
		return;
	}

	ll z = k * l;
	if(m >= z){
		cout<<0<<endl;
		return;
	}

	ll ans = l;
	ll div = (m - l) / (k - 1);
	if((m-l) % (k-1) != 0){
		div+=1;
	}

	ans = ans - div;
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
