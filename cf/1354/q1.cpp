#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll a,b,c,d;
	cin>>a>>b>>c>>d;

	if(b >= a){
		cout<<b<<endl;
		return;
	}

	if(c <= d){
		cout<<-1<<endl;
		return;
	}

	double kk = (double)(a - b) / (double)(c - d);
	ll k = ceil(kk);
	// cout<<k<<endl;
	ll ans = b + k*(c);
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
